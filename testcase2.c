#include "types.h"
#include "stat.h"
#include "user.h"

int j = 3;
int main(void)
{
	int pid;
	int numInitialFreePageParent = getNumFreePages();
	
	for(int i=0; i < 5; i++){
		pid = fork();
		if (pid == 0)
		{
			sleep(i*100);
			int numInitialFreePageChild = getNumFreePages();
			j = 4;
			int numFinalFreePageChild = getNumFreePages();
			if ((numInitialFreePageChild - numFinalFreePageChild) > 0)
				printf(1, "Number of free pages decreased\n");
			else
				printf(1, "Error: No decrease in number of free pages\n");
			exit();
		}
	}
	for (int i = 0; i < 5; i++)
		wait();
	printf(1, "Change in number of free pages after reaping child process: %d\n", getNumFreePages() - numInitialFreePageParent);
	exit();
}
