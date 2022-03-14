#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
/*Global variables*/
float x;
int y, z;
int n;
int numbers[50];

/*Functions index*/
void *a_average();
void *minimum();
void *maximum();

int main()
{
    pthread_t t_01;
    pthread_t t_02;
    pthread_t t_03;
    void *result;
    
    printf("Digite a quantidade de valores:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
	    printf("%dº número:",i+1);
		scanf("%d",&numbers[i]);
	}

    pthread_create(&t_01, NULL, &a_average, NULL);
    pthread_join(t_01, &result);

    pthread_create(&t_02, NULL, &minimum, NULL);
    pthread_join(t_02, &result);

    pthread_create(&t_03, NULL, &maximum, NULL);
    pthread_join(t_03, &result);

    printf("Média aritimétia: %.2f\n", x);
    printf("Menor número: %d\n", y);
    printf("Maior número: %d\n", z);

    return 0;
}

/*Function to calculate aritimetic avarage*/
void *a_average()
{
    float avrg = 0;
	for(int i=0;i<n;i++)
    {
		avrg += numbers[i];
    }
	x = avrg / n;
}

/*Function to filter lowest number*/
void *minimum()
{
    int i;
    int min = numbers[0];
    for (i = 1; i < n; i++ ) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    y = min;
}

/*Function to filter highest number*/
void *maximum()
{
    int i;
    int max = numbers[0];
    for (i = 1; i < n; i++ ) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    z = max;
}
