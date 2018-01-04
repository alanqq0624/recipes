#include <stdio.h>
#include <stdlib.h>

struct Prefix{
	unsigned int ip;
	unsigned char len;
	struct Prefix *next;
};
typedef struct Prefix prefix;

int counter = 0;//for counting the total number of prefixes in the “routing_table.txt”

void search(prefix *list, int cmd);
int powerint(int x, int n);
prefix *addfront(prefix *list,unsigned int ip, unsigned char len);
prefix *addback(prefix *list,unsigned int ip, unsigned char len);
prefix *input(int cmd);
void length_distribution(prefix *list);
void segment(prefix *list, int d);
void prefix_insert();
void prefix_delete();

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Usage: ./hw9 d");
		exit(1);
	}
	int d = atoi(argv[1]);
	if( (d>32) || (d<0)){
		printf("d should be an positive int range in 1~32)\n");
		exit(1);
	}
	prefix *data1;
	data1 = input(0);
	printf("%d\n", counter);
	printf("jizz\n");
	length_distribution(data1);

	return 0;
}

void search(prefix *list, int cmd){
	FILE *output;
	switch(cmd){
		case 1:
			output = fopen("output_1", "w");
			break;
		case 2:
			output = fopen("output_2", "w");
			break;
		case 3:
			output = fopen("output_3", "w");
			break;
		default:
			printf("jizz");
			exit(1);
	}
	prefix *trace = input(3);
	prefix *current;
	while(1){//loop to try every list
		current = trace;
		while(1){//loop to try every trace
			if(list->ip == current->ip && list->len == current->len){
				fprintf(output, "successful\n");
				break;
			}
			if(current->next == NULL){
				fprintf(output, "failed\n");
				break;
			}
			current = current->next;
		}

		if(list->next == NULL)break;

		list = list->next;
	}
}

int powerint(int x, int n){
	int i, ans = 1;
	for(i = 1; i <= n; i++){
		ans *= x;
	}
	return ans;
}

prefix *addfront(prefix *list,unsigned int ip, unsigned char len){
	prefix *add;
	add = malloc(sizeof(prefix));
	if(add == NULL){
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	add->ip = ip;
	add->len = len;
	add->next = list;
	return add;
}

prefix *addback(prefix *list,unsigned int ip, unsigned char len){
	prefix *add;
	add = malloc(sizeof(prefix));
	if(add == NULL){
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	add->ip = ip;
	add->len = len;
	while(list->next != NULL){
		list = list->next;
	}
	list->next = add;
	add->next = NULL;
	return add;
}

prefix *input(int cmd){
	counter = 0;
	FILE *input;
	switch(cmd){
		case 0:
			input = fopen("routing_table.txt", "r");
			break;
		case 1:
		    input = fopen("inserted_prefixes.txt", "r");
			break;
		case 2:
			input = fopen("deleted_prefixes.txt", "r");
			break;
		case 3:
			input = fopen("trace_file.txt", "r");
			break;
		default:
			printf("input cmd failed\n");
			exit(EXIT_FAILURE);
	}
	prefix *list = NULL;
	unsigned char ip[4];
	unsigned char len, junk;
	//00000000 00000000 00000000 00000000
	//3        2        1        0
	while(!feof(input)){
		fscanf(input, "%u", &ip[3]);
		//printf("%u.", ip[3]);
		junk = fgetc(input);// .
		fscanf(input, "%u", &ip[2]);
		//printf("%u.", ip[2]);
		junk = fgetc(input);// .
		fscanf(input, "%u", &ip[1]);
		//printf("%u.", ip[1]);
		junk = fgetc(input);// .
		fscanf(input, "%u", &ip[0]);
		//printf("%u", ip[0]);
		junk = fgetc(input);// /
		fscanf(input, "%u", &len);
		//printf("/%u", len);
		junk = fgetc(input);// /n

		if(feof(input))break;

		list = addfront(list, *((unsigned int*)&ip), len);
		counter++;
		//printf("\t %d\n", count);
	}
	
	fclose(input);
	return list;
}

void length_distribution(prefix *list){
	printf("jizz");

	int tmp;//convert char len from struct prefix to int
	int len_count[33];
	for(int i = 0; i < 33; i++)
		len_count[i] = 0;
	FILE* output;
	output = fopen("length_distribution", "w");

	while(1){
		tmp = list->len;
		len_count[tmp]++;
		if(list->next = NULL)
			break;
		else
			list = list->next;
	}

	//print out answer
	for(int i = 0; i < 33; i++){
		fprintf(output, "%d\n", len_count[i]);
	}
}

void segment(prefix *list, int d){
	//set group array by use pointer
	//it save the head of every group which is a link-list
	//use *group + n to access every group like *group[n]
	prefix **group = calloc(powerint(2,d)+1, sizeof(prefix*));

	//compare table which save the pattern if every group
	//index of compare table and group is equal
	unsigned int ctable[powerint(2,d)];
	for(unsigned int i = 0; i < powerint(2,d); i++){
		ctable[i] = i << (32-d);
		*(group+i) = NULL;//by the way , set all group array as initial -> null
	}

	while(1){
		if(list->len < d){
			
		}
	}
}

void prefix_insert(){

}

void prefix_delete(){

}
