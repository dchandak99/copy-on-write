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
