/*
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
  printf(1, "Hello, world!\n");
  exit();
}
*/
/*
// testcase0
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
	int numFreePagesInitial = getNumFreePages();
	int numVirtPagesInitial = getNumVirtPages();
	int numPhysPagesInitial = getNumPhysPages();
        int numPTPagesInitial = getNumPTPages();
	
	printf(1, "Initial: Free=%d, Virt=%d, Phys=%d, PT=%d\n",
	       numFreePagesInitial,numVirtPagesInitial,
               numPhysPagesInitial,numPTPagesInitial);
	
	sbrk(4096);

	int numFreePagesFinal = getNumFreePages();
	int numVirtPagesFinal = getNumVirtPages();
	int numPhysPagesFinal = getNumPhysPages();
        int numPTPagesFinal = getNumPTPages();
	
	printf(1, "Final: Free=%d, Virt=%d, Phys=%d, PT=%d\n",
	       numFreePagesFinal,numVirtPagesFinal,
               numPhysPagesFinal, numPTPagesFinal);

 	exit();
}

*/
/*
//testcase1
#include "types.h"
#include "stat.h"
#include "user.h"

int i = 3;
int main(void)
{
	int pid;
	int numInitialFreePageParent = getNumFreePages();
	pid = fork();
	if (pid == 0)
	{
		int numInitialFreePageChild = getNumFreePages();
		i = 4;
		int numFinalFreePageChild = getNumFreePages();
		if ((numInitialFreePageChild - numFinalFreePageChild) > 0)
			printf(1, "Number of free pages decreased\n");
		else
			printf(1, "Error: No decrease in number of free pages\n");
	}
	else
	{
		wait();
		printf(1, "Change in number of free pages after reaping child process: %d\n", getNumFreePages() - numInitialFreePageParent);
	}
	exit();
}

*/

//testcase2

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

