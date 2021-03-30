#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template<class T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if( this->first->link == 0 )
				return false;
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			else{
				Node<T> *current = this->first;
				this->first->link=current->link;
				element=current->data;
				delete current;
				this->first=current->link;
				this->current_size--;
				return true;}}
};

/*bool LinkedList::Delete(int &element){

        if (first == 0)
                return false;

        Node *current = first;
        Node *previous = 0;

        //마지막 노드까지 찾아가는 반복문
        while(1){
                if (current->link == 0){  //마지막 노드를 찾는것
                        if (previous)
                                previous -> link = current -> link;
                        else
                                first = first -> link;
                        break;
                }
                previous = current;
                current = current -> link;
        }
        element = current -> data;
        delete current;
        current_size--;

        return true;
}*/
			
