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
