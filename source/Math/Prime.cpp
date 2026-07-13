// 一、直接查，只問極少次，且數字可能很大 (n<= 1e14)
bool isPrime(long long n) { 
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// 二、埃式篩，建質數表，大量查詢 1 ~ 10^7 內的質數
const int MAXN = 1e7 + 10;
vector<int> primes;
bool is_prime[MAXN];

void build(int n) {
    primes.clear(); // 初始化
    fill(is_prime, is_prime + n + 1, true); // 初始化全設為true
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i); // 放到primes vector中記錄

            for (ll j = (ll)i * i; j <= n; j += i) is_prime[j] = false;
        }
    }
}

// 三、歐拉篩
#define MAXN 47000 //sqrt(2^31)=46,340...
bool isPrime[MAXN];
int p[MAXN];
int pSize=0;
void getPrimes(){
    pSize = 0; // 初始化
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i=2 ; i<MAXN ; i++){
        if(isPrime[i]) p[pSize++] = i;
        for(int j=0 ; j<pSize && i*p[j] <= MAXN ; ++j){
            isPrime[i*p[j]] = false;
            if(i%p[j]==0) break;
        }
    }
}


/*
problem :
給定整數 N，求N最少可以拆成多少個質數的和。
如果N是質數，則答案為1。
如果N是偶數(N!=2)，則答案為2(強歌德巴赫猜想)。
如果N是奇數且N−2是質數，則答案為2(2+質數)。
其他狀況答案為3(弱歌德巴赫猜想)。
*/
bool isPrime(int n){
    for(int i=2;i<n;++i){
        if(i*i>n) return true;
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(isPrime(n)) cout<<"1\n";
    else if(n%2==0||isPrime(n-2)) cout<<"2\n";
    else cout<<"3\n";
}