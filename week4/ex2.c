#include <unistd.h>

// Num of processes = 2 in power of forks
// so if we perform 3 forks - we will get 8 procs
// 5 forsk - 32 procs

int main(){
	for(int i = 0; i < 5; i++){
		fork();
	}
	sleep(5);
	return 0;
}