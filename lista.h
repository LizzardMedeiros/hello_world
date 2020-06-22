#include <stdlib.h>
#include <fstream.h>
//#include <string.h>

//using namespace std;
/*Declarando os Componentes da Lista


-------------------------------------
*/

//==========Estruturas (tipos de dados) Fundamentais==========

//Criar um tipo de dado, "TipoItem"

struct TipoItem
{
     int id;
     char insc[6];
     char nome[20];
     int nota;
 //    nota = atoi(not);
};

//Criar um tipo de dado "Celula".

struct Celula
{
       TipoItem candidato; // Conteudo da celula
       Celula *prox, *ant;
};

//Criar um tipo de dado "TipoLista"

struct TipoLista
{
       Celula *primeiro, *ultimo;
};

//=====================Função Essencial========================

//Criação de uma lista vazia a partir de uma função

void ListaVazia(TipoLista *Lista)
{
     Lista->primeiro = new Celula[1]; //Cria 1 vetor tipo Celula como primeiro (Celula Cabeça)
     Lista->ultimo = Lista->primeiro; //Cria 1 vetor tipo Celula como ultimo (Celula calda)
     Lista->primeiro->prox = NULL; //faz o ponteiro "prox" da primeira celula (cabeça), apontar para nada
     Lista->primeiro->ant = NULL; // faz o ponteiro "ant da ultima celula (calda), apontar para o nada
}

//====================Funções Auxiliares============================

//Insere celulas na Lista
int vazia (TipoLista Lista)
{
    return(Lista.primeiro == Lista.ultimo);
}

Celula *busca (int id, TipoLista Lista)
{
   Celula *p;
   p = Lista.primeiro;
   while (p != NULL && p-> candidato.id != id)
      p = p->prox;
   return p;
}

void insere(TipoItem candidato_x, TipoLista *y)
{
     y -> ultimo -> prox = new Celula[1]; // Cria uma celula vazia na ultima posição
     y -> ultimo -> prox -> ant = y -> ultimo;
     y -> ultimo = y -> ultimo -> prox;
     y -> ultimo -> candidato = candidato_x;
     y -> ultimo -> prox = NULL;
}


void insere_meio(TipoItem candidato_x, Celula *y)
{
    Celula *novo_candidato;
    novo_candidato = new Celula[1];
    novo_candidato->candidato = candidato_x;
    novo_candidato->prox = y->prox;
    y->prox = novo_candidato;
}

//Retira celulas da lista
void Retira(TipoItem *candidato_x, Celula *y, TipoLista *z)
{
    /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
    Celula *q;
    if (vazia(*z) || y == NULL || y->prox == NULL)
    {
        return;
    }

    q = y->prox;
    *candidato_x = q -> candidato;
    y->prox = q->prox;
    q->prox->ant = y;
    if (y -> prox == NULL)
        z->ultimo = y;

    delete(q);
}
void Imprime(TipoLista Lista, char *name)
{
   Celula *p;
   p = Lista.primeiro;
   ofstream arq (name);
   while (p->prox != 0)
   {
        if(!arq)
        {
            return;
        }
        p = p->prox;
        arq<<p->candidato.id<<"\t"<<p->candidato.insc<<"\t"<<p->candidato.nome<<"\t"<<p->candidato.nota<<"\n";
   }
     arq.close();
     return;
}

int Filtro(int n, int Vagas)
{
     if(n == 0){return 0;}
     int i, z=0, apr=0, rep=0;
     
     Celula *Apr;
     Celula *Rep;
     
     TipoItem Cand;
     
     TipoLista Aprovados;
     ListaVazia(&Aprovados);
     TipoLista Reprovados;
     ListaVazia(&Reprovados);
           
     ifstream ler ("vestibular.txt");
     while(z<n)
     {
             ler >> Cand.id >> Cand.insc >> Cand.nome >> Cand.nota;
             if(Vagas != 0)
             {
                          Vagas --;
                          apr ++;
                          insere(Cand, &Aprovados);
             }else{
                          rep ++;
                          insere(Cand, &Reprovados);
             }
               z++;
     }
     if(apr>0){
     Imprime(Aprovados, "aprovados.txt");
     }
     if(rep>0){
     Imprime(Reprovados,"reprovados.txt");
     }          
     ler.close();
     return 1;            
}
