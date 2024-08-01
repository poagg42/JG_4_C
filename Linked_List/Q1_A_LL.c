//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section A - Linked List Questions
Purpose: Implementing the required functions for Question 1 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList


///////////////////////// function prototypes ////////////////////////////////////

//You should not change the prototype of this function
int insertSortedLL(LinkedList *ll, int item);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	LinkedList ll;
	int c, i, j;
	c = 1;

	//Initialize the linked list 1 as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	printf("1: Insert an integer to the sorted linked list:\n");
	printf("2: Print the index of the most recent input value:\n");
	printf("3: Print sorted linked list:\n");
	printf("0: Quit:");

	while (c != 0)
	{
		printf("\nPlease input your choice(1/2/3/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j = insertSortedLL(&ll, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			printf("The value %d was added at index %d\n", i, j);
			break;
		case 3:
			printf("The resulting sorted linked list is: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}


	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

int insertSortedLL(LinkedList *ll, int item)
{
	/* add your code here */
	// ListNode라는 형식으로 *newNode, *cur, *prev를 설정하라.
	
	ListNode *newNode, *cur, *prev; 
	int index = 0;

	// newNode는 ListNode* 라는 데이터 형식을 가지고 ListNode의 사이즈만큼 동적 메모리 할당을 한 것을 담은 변수이다.
	newNode = (ListNode*)malloc(sizeof(ListNode));

	// 만약 newNode가 NULL이라면 -1을 return하라.
	if (newNode == NULL) {
		return -1;
	}

	// newNode에 접근해 item 필드 초기화
	 
	newNode -> item = item;

	// newNode에 접근해 next 필드 초기화
	newNode -> next = NULL;

	// 만약 ll의 head가 NULL이면
	if (ll -> head == NULL) {

		// ll의 head 멤버변수에 newNode를 저장한다.
		ll -> head = newNode;
		ll -> size++;

		// 신규 추가
		return 0;

	// 맨 앞에 삽입해야 하는 경우
	// 리스트가 비어있거나 첫 번째 노드의 값이 삽입하려는 값보다 크거나 같은 경우
	} else if (ll -> head -> item >= item) {
		newNode -> next = ll -> head;
		ll -> head = newNode;
		ll -> size++;
		return 0;
	
	// 리스트의 중간 또는 끝에 삽입해야 하는 경우
	} else {
		prev = NULL;
		cur = ll -> head;
		// cur이 NULL이 아니고 아이템으로 보낸 게 item보다 작은 경우
		// prev는 현재 노드의 이전 노드를 가리키고, cur는 현재 노드를 가리킵니다.

		while (cur != NULL && cur -> item < item) {
			prev = cur;
			cur = cur -> next;
			index++;
		}

		// newNode는 새로운 노드를 prev와 cur 사이에 삽입합니다.

		newNode -> next = cur;
		prev -> next = newNode;
		ll -> size++;
		return index;
	}
}

///////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	// ListNode라는 형식의 cur 포인터를 선언한다.
	ListNode *cur;

	// 만약 ll 포인터 변수가 NULL이라면 반환한다.
	if (ll == NULL)
		return;

	// cur를 링크드리스트의 첫 노드로 저장한다.
	cur = ll->head;

	// 만약 cur이 NULL이면 Empty를 출력한다. 그리고 줄바꿈 출력 후 반환.

	if (cur == NULL)
		printf("Empty");

	// cur이 NULL이 아니라면

	while (cur != NULL)

	{

 	// cur.item을 출력하고 cur에 cur.next를 저장한다.
		printf("%d ", cur->item);
		cur = cur->next;
	}

	// 줄바꿈을 출력한다.
	printf("\n");
}

void removeAllItems(LinkedList *ll)
{
	// cur포인터를 링크드리스트의 첫 노드로 설정한다.
	ListNode *cur = ll -> head; 

	// tmp 포인터를 선언한다.
	ListNode *tmp;

	// 만약 포인터 cur이 NULL이 아닐 경우 반복한다.
		while (cur != NULL){
		// tmp는 cur 포인터의 다음 노드로 설정한다.
			tmp = cur -> next;

		// cur 포인터가 가리키는 메모리를 해제한다.

			free(cur);

		// cur 포인터에 tmp 포인터 값을 넣는다.
			cur = tmp;
		}

	// 링크드리스트의 첫 노드를 NULL로 바꾼다.
	ll -> head = NULL;

	// 링크드리스트의 크기를 0으로 바꾼다.
	ll -> size = 0;

}

ListNode *findNode(LinkedList *ll, int index){

	// ListNode라는 형식의 포인터 변수 temp를 설정한다.
	ListNode *temp;

	// 만약 ll이 NULL이거나 index가 0보다 작거나 index가 ll의 size보다 크다면 NULL을 반환한다.

	if (ll == NULL || index < 0 || index >= ll -> size)
		return NULL;

	// temp 변수에 ll의 head를 담는다.
	temp = ll -> head;


	// 만약 temp가 NULL이거나 index가 0보다 작으면 NULL을 반환한다.
	if (temp == NULL || index < 0)
		return NULL;

	// index가 0보다 클 때 반복한다.

	while (index > 0){
		// temp를 다음 노드로 설정한다.
		temp = temp -> next;
		// 만약 temp가 NULL이면 NULL을 반환한다.
		if (temp == NULL)
			return NULL;

		// index를 1 줄인다.

		index--;
	}

	// temp를 반환한다.

	return temp;

}

int insertNode(LinkedList *ll, int index, int value){

	// ListNode 타입의 포인터 변수 *pre, *cur을 만든다.
	ListNode *pre, *cur;


	// 만약 ll이 NULL이거나 index가 0보다 작거나 index가 linkedlist의 size + 1보다 크면 -1을 반환한다.
	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){

		// cur를 ll의 head로 저장한다.
		cur = ll->head;

		// ll의 head를 ListNode의 사이즈만큼 동적 메모리 할당한다.
		ll->head = malloc(sizeof(ListNode));

		// ll의 head의 item에 value값을 저장한다.
		ll->head->item = value;

		// ll의 head의 next에 cur값을 저장한다.
		ll->head->next = cur;

		// ll의 size를 1 늘린다.
		ll->size++;

		// 0 반환
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links

	// 노드를 찾았을 때 NULL이 아니면 pre에 저장한다.
	if ((pre = findNode(ll, index - 1)) != NULL){

		// pre의 next를 cur에 저장한다.
		cur = pre->next;

		// ListNode의 size만큼 pre.next에 동적 메모리 할당한다.
		pre->next = malloc(sizeof(ListNode));

		// value값을 pre.next.item에 저장한다.
		pre->next->item = value;

		// cur값을 pre.next.next에 저장한다.
		pre->next->next = cur;

		// ll.size를 1늘린다.
		ll->size++;

		// 0을 반환한다.
		return 0;
	}

	// 모두 아니라면 -1 반환

	return -1;
}


int removeNode(LinkedList *ll, int index){

	// ListNode 타입의 포인터 변수 *pre, *cur을 선언합니다.
	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	// 만약 ll이 NULL이거나 index가 0보다 작거나 index가 ll의 size보다 클 경우 -1을 반환한다.
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer

	// 만약 인덱스가 0일 경우
	if (index == 0){

		// cur은 head의 next로 설정한다.
		cur = ll->head->next;

		// ll -> head 노드의 메모리를 해제한다.
		free(ll->head);

		// head노드를 cur로 초기화한다.
		ll->head = cur;

		// ll의 size를 -1한다.
		ll->size--;

		// 0을 return한다.
		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links

	// pre 변수에 ll, index -1로 노드를 찾은 결과를 담고 그것이 NULL이 아닐 때
	if ((pre = findNode(ll, index - 1)) != NULL){

		// 만약 pre -> next가 NULL이 맞다면 -1을 반환한다.
		if (pre->next == NULL)
			return -1;

		// cur 변수에 pre.next를 저장한다.
		cur = pre->next;

		// pre.next에 cur.next를 저장한다.
		pre->next = cur->next;

		// cur를 메모리 해제한다.
		free(cur);

		// ll의 size를 -1한다.
		ll->size--;

		// 0을 반환한다.
		return 0;
	}

	// -1을 리턴한다.
	return -1;
}
