#include <iostream>

using namespace std;

struct node{ //Bagli liste
    int data;
    node* next;
};


struct queue{ //Kuyruk
    int indis=0;
    node *front=NULL;
    node *rear=NULL;
};


struct stack{ //Stack
    int counter=0;
    node *top=NULL;
};

void push(stack *s, int harf){ //Stack ekleme
    node *eleman= new node();
    eleman->data=harf;

    if(s->counter==0) { //Stack bos ise
        eleman->next=NULL;
        s->top=eleman;
        s->counter++;}
    else{
        eleman->next=s->top; //yeni düðüm, top düðümün önüne eklenir
        s->top=eleman; //yeni düðüm artýk top düðüm olur
        s->counter++;}
}

void enqueue(queue *q, int harf){
    node *eleman= new node();
    eleman->data=harf;

    if(q->indis==0){
        eleman->next=NULL;
        q->front=q->rear=eleman;
        q->indis++;}

    else{
        eleman->next=q->rear;
        q->rear=eleman;
        q->indis++;}

}

int pop(stack *s){
    if(s->counter==1){
        int x= s->top->data;
        delete s->top;
        s->top=NULL;
        s->counter--;
        return x;}

    else{
        int x= s->top->data;
        node *temp= s->top->next;
        delete s->top;
        s->top=temp;
        s->counter--;
        return x;
    }

}

int dequeue(queue *q){
    if(q->indis==1){
        int x= q->front->data;
        delete q->front;
        q->front= q->rear=NULL;
        q->indis--;
        return x;}

    else{
        int x= q->front->data;
        node *iter=q->rear;
        while(iter->next!=q->front)
            iter= iter->next;
        delete q->front;
        q->front=iter;
        q->front->next=NULL;
        q->indis--;
        return x;}
}


int main()
{
    stack s; queue q; int i=0, sonuc=0; string kelime= "";
    cout << "Kelime giriniz: "; cin >> kelime;
    while(i<kelime.length()){ //Harfler sirayla ASCII degerlerine gore eklenecek
        push(&s, kelime[i]);
        enqueue(&q, kelime[i]);
        i++;}

    while(!(s.counter==0)){
        if(pop(&s) != dequeue(&q)){ //Stack'ten cikan son- Queue'dan cikan ilk harf esit mi?
            sonuc=1;
            break;}}

    if(sonuc==0) { cout << kelime << " kelimesi palindromdur!" << endl;}
    else { cout << kelime << " kelimesi palindrom degildir!" << endl;}


    return 0;
}
