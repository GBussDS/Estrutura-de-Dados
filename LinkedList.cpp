#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct Node
{
    int iMatricula;
    string strNome;
    Node* ptrNext;   
} Node;

typedef struct LinkedList
{
    Node* ptrFirst;
} LinkedList;

LinkedList* newLinkedList();
Node* newNode(int, string);
void addStudent(LinkedList* const, int, string);
void ShowStudents(LinkedList* const);
void removeStudent(LinkedList* const, int);
void ChangeStudents(LinkedList* const);
LinkedList* intercecao(LinkedList* const, LinkedList* const);
int checarLoop(LinkedList* const);
int checarLoopLebre(LinkedList* const);
void inverterLista(LinkedList* const);
void ordenarLista(LinkedList* const);

int main()
{
    LinkedList* linkedList = newLinkedList();
    addStudent(linkedList, 51089, "Guilherme");
    addStudent(linkedList, 51098, "Gustavo");
    addStudent(linkedList, 51065, "João");
    
    LinkedList* linkedList2 = newLinkedList();
    addStudent(linkedList2, 51039, "Guilherme");
    addStudent(linkedList2, 51098, "Gustavo");
    addStudent(linkedList2, 51055, "João");
    
    LinkedList* linkedListIntercecao = intercecao(linkedList, linkedList2);
    
    // ChangeStudents(linkedList);
    ShowStudents(linkedListIntercecao);
    
    Node* temp = linkedList->ptrFirst;
    
    // Making the linked list loop
    while (temp->ptrNext != nullptr)
    {
        temp = temp->ptrNext;
    }
    temp->ptrNext = linkedList->ptrFirst;
    
    cout << checarLoop(linkedList) << endl;
    cout << checarLoopLebre(linkedList) << endl;
    cout << checarLoopLebre(linkedList2) << endl;
    
    inverterLista(linkedList2);
    
    cout<< "++++++++++++++++++++++++++++++++++++" << endl;
    ordenarLista(linkedList2);
    ShowStudents(linkedList2);
    
    return 0;
}

LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr;
    
    return temp;
}

Node* newNode(int iMatricula, string strNome)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iMatricula = iMatricula;
    temp->strNome = strNome;
    temp->ptrNext = nullptr;
    
    return temp;
}

void addStudent(LinkedList* const linkedList, int iMatricula, string strNome)
{
    Node* temp = newNode(iMatricula, strNome);
    if (linkedList == nullptr)
    {
        cout << "Lista não existe - addStudent" << endl;
    }
    else if (linkedList->ptrFirst == nullptr)
    {
        linkedList->ptrFirst = temp;
    }
    else
    {
        Node* lastNode = linkedList->ptrFirst;
        
        while (lastNode->ptrNext != nullptr)
        {
            lastNode = lastNode->ptrNext;
        }
        
        lastNode->ptrNext = temp;
    }
}

void ShowStudents(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista não existe - ShowStudents" << endl;
    }
    else
    {
        Node* current = linkedList->ptrFirst;
        
        while (current != nullptr)
        {
            cout << "Matricula: " << current->iMatricula << ", Nome: " << current->strNome << endl;
            current = current->ptrNext;
        }
    }
}

void removeStudent(LinkedList* const linkedList, int iMatricula)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista não existe ou vazia." << endl;
    }
    else if (linkedList->ptrFirst->iMatricula == iMatricula)
    {
        Node* current = linkedList->ptrFirst;
        linkedList->ptrFirst = current->ptrNext;
        free(current);
    }
    else
    {
        Node* current = linkedList->ptrFirst;
        Node* lastNode = current;
        
        while (current->iMatricula != iMatricula)
        {
            lastNode = current;
            current = current->ptrNext;
            
            if (current == nullptr)
            {
                cout << "Aluno não encontrado." << endl;
                return;
            }
        }
        
        lastNode->ptrNext = current->ptrNext;
        free(current);
    }
}

void ChangeStudents(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista não existe ou vazia" << endl;
    }
    else if (linkedList->ptrFirst->ptrNext == nullptr)
    {
        return;
    }
    else
    {
        Node* current = linkedList->ptrFirst;
        Node* lastNode = current;
        
        while (current->ptrNext != nullptr)
        {
            lastNode = current;
            current = current->ptrNext;
        }
        
        lastNode->ptrNext = linkedList->ptrFirst;
        current->ptrNext = linkedList->ptrFirst->ptrNext;
        linkedList->ptrFirst->ptrNext = nullptr;
        linkedList->ptrFirst = current;
    }
}

LinkedList* intercecao(LinkedList* const linkedList1, LinkedList* const linkedList2)
{
    LinkedList* linkedListIntercecao = newLinkedList();
    
    if (linkedList1 == nullptr || linkedList1->ptrFirst == nullptr || linkedList2 == nullptr || linkedList2->ptrFirst == nullptr)
    {
        return linkedListIntercecao;
    }
    else
    {
        Node* current1 = linkedList1->ptrFirst;
        
        while (current1 != nullptr)
        {
            Node* current2 = linkedList2->ptrFirst;
            
            while (current2 != nullptr)
            {
                if (current1->iMatricula == current2->iMatricula)
                {
                    addStudent(linkedListIntercecao, current1->iMatricula, current1->strNome);
                }
                current2 = current2->ptrNext;
            }
            
            current1 = current1->ptrNext;
        }
        
        return linkedListIntercecao;
    }
}

int checarLoop(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia ou inexistente - checarLoop." << endl;
        return 0;
    }
    else
    {
        Node* current1 = linkedList->ptrFirst;
        
        while (current1->ptrNext != nullptr)
        {
            Node* current2 = current1->ptrNext;
            int iLoopSize = 0;
            
            while (current2 != nullptr && iLoopSize != 10000)
            {
                iLoopSize += 1;
                if (current1 == current2)
                {
                    return iLoopSize;
                }
                current2 = current2->ptrNext;
            }
            
            current1 = current1->ptrNext;
        }
        
        return 0;
    }
}

int checarLoopLebre(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia ou inexistente - checarLoop." << endl;
        return 0;
    }
    else
    {
        Node* current1 = linkedList->ptrFirst;
        Node* current2 = current1->ptrNext; 
        
        while (current1 != current2 && current2->ptrNext->ptrNext != nullptr)
        {
            current1 = current1->ptrNext;
            current2 = current2->ptrNext->ptrNext;
        }
        
        if (current2->ptrNext->ptrNext == nullptr)
        {
            return 0;
        }
        
        return 1;
    }
}

void inverterLista(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia ou inexistente - inverterLista." << endl;
        return;
    }
    else if (linkedList->ptrFirst->ptrNext == nullptr)
    {
        cout << "Lista invertida!" << endl;
        return;
    }
    else
    {
        ShowStudents(linkedList);
        
        Node* current = linkedList->ptrFirst;
        Node* lastNode = nullptr;
        Node* nextNode = current->ptrNext;
        
        while (nextNode != nullptr)
        {
            current->ptrNext = lastNode;
            
            lastNode = current;
            current = nextNode;
            nextNode = current->ptrNext;
        }
        current->ptrNext = lastNode;
        
        linkedList->ptrFirst = current;
        
        cout << "Lista invertida!" << endl;
        ShowStudents(linkedList);
    }
}

void ordenarLista(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia ou inexistente - ordenarLista." << endl;
        return;
    }
    else if (linkedList->ptrFirst->ptrNext == nullptr)
    {
        cout << "Lista ordenada!" << endl;
        return;
    }
    else
    {
        Node* current = linkedList->ptrFirst;
        Node* previous = nullptr;
        Node* next = current->ptrNext;
        
        while (next != nullptr)
        {
            if (current->iMatricula < next->iMatricula)
            {            
                if (current == linkedList->ptrFirst)
                {
                    linkedList->ptrFirst = next;
                    current->ptrNext = next->ptrNext;
                    next->ptrNext = current;
                    
                }
                else
                {
                    previous->ptrNext = next;
                    current->ptrNext = next->ptrNext;
                    next->ptrNext = current;
                }
                
                current = linkedList->ptrFirst;
                previous = nullptr;
                next = current->ptrNext;
            }
            else
            {
                previous = current;
                current = next;
                next = current->ptrNext;
            }
        }
        
        cout << "Lista ordenada!" << endl;
        return;
    }
}

