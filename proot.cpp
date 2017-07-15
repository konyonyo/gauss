#include <iostream>
#include <cmath>

bool isHehoJoyo(int a, int p){
  int tmp = a;
  for(int i=2; i<=(int)((p - 1) / 2); ++i){
    tmp = (tmp * a) % p;
  }

  return tmp == 1;
}

int getPrimitiveRoot(int p){
  // check if i is primitive root of p
  for(int i=2; i<p; ++i){
    int tmp = i;
    for(int j=2; j<p; ++j){
      tmp = (tmp * i) % p;

      if(tmp == 1){
        // found primitive root
        if(j == p-1){
          return i;
        }else{
          break;
        }
      }
    }
  }
  return 0;
}

bool isPrimary(int n){
  for(int i=2; i<n; ++i){
    if(n % i == 0){
      return false;
    }
  }

  return true;
}

int main(int argc, char* argv[]){
  for(int i=3; i<1000; ++i){
    if(isPrimary(i)){
      std::cout << i
       << ", primitive root: " << getPrimitiveRoot(i)
       << ", -1 is heho joyo: " << isHehoJoyo(i - 1, i)
       << ", mod 4: " << i % 4 << "\n";
    }
  }

  return 0;
}

