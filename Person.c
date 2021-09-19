#include <stdio.h>
#include <string.h>
#include "Person.h"

Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("{%s | %c | %s}", p.name, p.sex, p.city);
}
void init_SAL(PersonStaticArrayList *list)
{
	list->count=0;
}
void insert_first_SAL(PersonStaticArrayList *list, Person p)
{
	int x;
	if(list->count<MAX_LIST){
		for(x=list->count; x>=0; x--){
			list->data[x] = list->data[x-1];
		}
		list->data[x] = p;
	}
}
void insert_last_SAL(PersonStaticArrayList *list, Person p)
{
	if(list->count<MAX_LIST){
		list->data[list->count] = p;
		list->count++;
	}
}
void insert_at_SAL(PersonStaticArrayList *list, Person p, int index)
{
	int x;
	if(list->count<MAX_LIST && (index < list->count && index >= 0)){
		for(x=list->count; x>=index; x--){
			list->data[x] = list->data[x-1];
		}
		list->data[x] = p;
	}
	
}
void delete_first_SAL(PersonStaticArrayList *list)
{
	int x;
	if(list->count > 0){
		for(x=0; x<list->count; x++){
			list->data[x] = list->data[x+1];
		}
		list->count--;
	}
}
void delete_last_SAL(PersonStaticArrayList *list)
{
	if(list->count >0){
		list->count--;
	}
}
// all ocurrences
void delete_by_sex_SAL(PersonStaticArrayList *list, char sex)
{
	int x,y;
	if( list->count >0){
		for(x=0; x<list->count; x++){
			if(list->data[x].sex =='m' || list->data[x].sex == 'M'){
				for(y=x; y < list->count; y++){
					list->data[y] = list->data[y+1];
				}
				list->count--;
			}
		}
	}
}
void display_SAL(PersonStaticArrayList list)
{
	int x;
	for(x=0; x <= list.count; x++){
		printf("ArrayList of Person Static: \n", list.data[x]);
	} 
}

/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list)
{
	void init_DAL(PersonDynamicArrayList *list){
	list->data = (Person*)malloc(sizeof(Person)*MAX_LIST);
	list->count=0;
	list->max=MAX_LIST;
}
void insert_first_DAL(PersonDynamicArrayList *list, Person p)
{
	int x;
	if(list->count==list->max){
		list->max*=2;
	}
	
	for(x=list->count; x>0; x--){
		list->data[x]=list->data[x-1];
	}
	
	list->data[x]=p;
}
void insert_last_DAL(PersonDynamicArrayList *list, Person p)
{
	list->count++;
}
void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index)
{
}
void delete_first_DAL(PersonDynamicArrayList *list)
{
	if(list->count>0){
		list->count--;
	}
}
void delete_last_DAL(PersonDynamicArrayList *list)
{
	if(list->count>0){
		list->count--;
	}
}
 // first ocurrence
void delete_by_city_DAL(PersonDynamicArrayList *list, String city)
{
	int x,y;
}
void display_DAL(PersonDynamicArrayList list)
{
	int x;
	
	for(x=0; x<list->count ; x++){
		printf("%s ",list->data[x].name);
	}
}




