#include <stdio.h>

struct student
{
	int rno;
	char name[20];
	float marks;
};

void accept(struct student s[10], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter the details for student %d: \n", i+1);
		printf("Enter the roll no:  ");
		scanf("%d", &s[i].rno);
		printf("Enter the name:  ");
		scanf("%s", s[i].name);
		printf("Enter the marks:  ");
		scanf("%f", &s[i].marks);
		printf("\n");
	}
}

void display(struct student s[10], int n)
{
	printf("R no.\tName\tMarks\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%s\t%f\n", s[i].rno, s[i].name, s[i].marks);
	}
}

void linear_search(struct student s[10], int n, int target)
{
	int freq = 0;
	for (int i = 0; i < n; i++)
	{
	
		if (s[i].rno == target)
		{
			freq++;
			printf("Student found! \n");
			printf("R no.\tName\tMarks\n");
			printf("%d\t%s\t%f\n", s[i].rno, s[i].name, s[i].marks);
			printf("Frequency: %d\n", freq);
			return;
		}
		else
		{
			freq++;
		}
	}
	printf("Frequency: %d\n", freq);
	printf("Student not found!\n");
}

void binary_search_non_rec(struct student s[10], int low, int high, int target)
{
	int freq = 0;
	while (low<=high)
	{
		int mid = (low+high)/2;
		if (s[mid].rno == target)
		{
			freq++;
			printf("Student found! \n");
			printf("These are the details for student %d: \n", mid+1);
			printf("R no.\tName\tMarks\n");
			printf("%d\t%s\t%f\n", s[mid].rno, s[mid].name, s[mid].marks);
			printf("Frequency: %d\n", freq);
			return;
		}
		else if (target < s[mid].rno)
		{
			freq++;
			high = mid-1;
		}
		else {low = mid + 1;freq++;}
	}
	printf("Frequency: %d\n", freq);
	printf("Student not found!\n");
}


void binary_search_rec(struct student s[10], int low, int high, int target)
{

	if (low<=high)
	{
		int mid = (low+high)/2;
		
		if (s[mid].rno == target)
		{
			printf("Student found! \n");
			printf("These are the details for student %d: \n", mid+1);
			printf("R no.\tName\tMarks\n");
			printf("%d\t%s\t%f\n", s[mid].rno, s[mid].name, s[mid].marks);
			return;
		}
		else if (target < s[mid].rno)
		{
			return binary_search_rec(s, low, mid-1, target);
		}
		else 
		{
			return binary_search_rec(s, mid+1, high, target);
		}
		
		printf("Student not found!\n");
		return;
	}
}


void selection_sort(struct student s[10], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int minpos = i;
		
		for (int j = i+1; j < n; j++)
		{
			if (s[j].rno < s[minpos].rno)
			{
				minpos = j;
			}
		}
		if (minpos!=i)
		{
			struct student temp = s[i];
			s[i] = s[minpos];
			s[minpos] = temp;
		}
	}
}

void bubble_sort(struct student s[10], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (s[j].rno > s[j+1].rno)
			{
				struct student temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}	
		}	
	}
}


int main()
{
	
	struct student s[10];
	int n;
	printf("Number of students: ");
	scanf("%d", &n);
	
	accept(s,n);
	display(s,n);
	printf("\n");
	
	int istrue=1;
	while(istrue == 1)
	{
		printf("Choose 1 for Linear Search.\n");
		printf("Choose 2 for Binary Search. (non rec)\n");
		printf("Choose 3 for Binary Search. (rec)\n");
		printf("Choose 4 to EXIT..\n");
		printf("Enter choice: \n");
		int choice;
		int temp;
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("Enter the roll no for student to be searched (linear search): ");
				scanf("%d", &temp);
				linear_search(s,n,temp);
				printf("\n");
				break;
			case 2:
				printf("Enter the roll no for student to be searched (binary search non rec): ");
				scanf("%d", &temp);
				selection_sort(s,n);
				printf("Sorted Input:\n");
				display(s,n);
				binary_search_non_rec(s,0,n,temp);
				printf("\n");
				break;
			case 3:
				printf("Enter the roll no for student to be searched (binary search rec): ");
				scanf("%d", &temp);
				bubble_sort(s,n);
				printf("Sorted Input:\n");
				display(s,n);
				binary_search_rec(s,0,n,temp);
				printf("\n");
				break;
			case 4:
				istrue=0;
				break;
		}
	}
	
	
	return 0;
	
	
	
	
}
