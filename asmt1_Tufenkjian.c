// ============================================================================
// Name: ASHOD CHRIS TUFENKJIAN
// Description: CPI CALCULATIONS PROJECT
// Due: September 18th, 2014
// COMP 222
// ============================================================================
#include <stdio.h>
#include <stdlib.h>
//global variables
int  nmbr_instr_classes;
int	 freq;
int* cpi     = NULL;
int* count   = NULL;
int  instruction_total = 0;
int  cycle_total = 0;

void allocate_memory()
{
	cpi 	=  (int*) malloc (nmbr_instr_classes*sizeof(int));
	count   =  (int*) malloc (nmbr_instr_classes*sizeof(int));
	return;
}

void deallocate_memory()
{
	if (cpi != NULL)
		free(cpi);
	if (count != NULL)
		free(count);
		return;
}

void enter_params()
{
	printf("Enter the number of instruction classes: ");
	scanf("%d", &nmbr_instr_classes);

    printf("Enter the frequency of the machine (MHz): ");
	scanf("%d", &freq);

	allocate_memory();

   	int i;
        for (i = 0;i<nmbr_instr_classes;i++)
        {
            int i_text = i + 1;
            printf("Enter CPI of class %d: ",(int)i_text);
            scanf("%d", &cpi[i]);

            printf("Enter instruction count of class %d (millions):",(int)i_text);
            scanf("%d", &count[i]);

            instruction_total += count[i];
            cycle_total += cpi[i]*count[i];
        }
	return;
}

void print_params()
{
    int p;

    printf("-------------------------\n");
    printf("| Class |  CPI  | Count |\n");
    for (p = 0; p < nmbr_instr_classes; p++)
    {
        int print_p = p + 1;
        printf("| %05d | %05d | %05d |\n",
               (int)print_p,(int)cpi[p],(int)count[p]);
    }
    printf("-------------------------\n");
    return;
}

float calc_avg_cpi()
{
	float  avg_cpi = ((1.0)*cycle_total) / instruction_total;
	return avg_cpi;
}

float calc_cpu_time()
{
	float  cpu_time = ((1.0)*cycle_total)*1000000 / (freq * 1000);
	return cpu_time;
}

float calc_mips()
{
    float mips = freq/calc_avg_cpi();
    return mips;
}

void print_performance()
{
    float average_CPI = calc_avg_cpi();
	float cpu_time	  = calc_cpu_time();
	float mips 		  = calc_mips();

	printf("-------------------------\n");
    printf("|Performance    |Value  |\n");
    printf("-------------------------\n");
    printf("|Average CPI    |%07.2f|\n",(float)average_CPI);
    printf("-------------------------\n");
    printf("|CPU Time(ms)   |%07.2f|\n",(float)cpu_time);
	printf("-------------------------\n");
    printf("|MIPS           |%07.2f|\n",(float)mips);
	printf("-------------------------\n");
	return;
}

int main ()
{   int x = 1;
    while (x == 1)
    {
        int selection;

        printf("\nPerformance Assessment: \n");
        printf("-----------------------\n");
        printf("1) Enter parameters\n");
        printf("2) Print table of parameters\n");
        printf("3) Print table of performance\n");
        printf("4) Quit\n\n");
        printf("Enter Selection: ");
        scanf("%d", &selection);

            if      (selection == 1)
            enter_params();
            else if (selection == 2)
            print_params();
            else if (selection == 3)
            print_performance();
            else if (selection == 4)
            {
                deallocate_memory();
               	x = 2;
            }
    }
    return 0;
}
