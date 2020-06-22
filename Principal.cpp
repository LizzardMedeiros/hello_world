#include <windows.h>
#include "lista.h"
#include "auxiliar.h"

int Tamanho = 0, id = 0, Vagas = 0;

TipoItem new_cand = {0,"0","0",1};

char TempNota[4] = "0";
char vagas[3] = "0";

TipoLista lista; // Declara uma Lista
Celula *Cel; //Declara um ponteiro Celula
//====================================================
/*  Declara os Processos da janela */
LRESULT CALLBACK ProcessosJanela (HWND, UINT, WPARAM, LPARAM);
HMENU menu;
/*  Make the class name into a global variable  */
char szClassName[ ] = "CONTROLE";

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nFunsterStil)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG acao;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = ProcessosJanela;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH)(COLOR_WINDOW);

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           WS_EX_CLIENTEDGE,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Gestão Vestibular",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           400,                 /* The programs width */
           300,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           0,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);
    menu = LoadMenu(hThisInstance, MAKEINTRESOURCE(NOVO_MENU));
    SetMenu(hwnd, menu);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&acao, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&acao);
        /* Send message to WindowProcedure */
        DispatchMessage(&acao);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return acao.wParam;

}

/*  This function is called by the Windows function DispatchMessage()  */

//=============================================================================

//==============================================================================

LRESULT CALLBACK ProcessosJanela (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    RECT rc;
    PAINTSTRUCT ps;
    switch (message)                  /* handle the messages */
    {
    //================MENU=======================
        case WM_CREATE:
        break;
        case WM_COMMAND:
             if (HIWORD(wParam) == BN_CLICKED)
             {
                switch (LOWORD(wParam))
                {
                case BUTTONOK:
                           new_cand.id = id;
                           SendMessage((HWND)NomeInput,(UINT)EM_GETLINE,(WPARAM)1,(LPARAM)new_cand.nome);
                           SendMessage((HWND)NotaInput,(UINT)EM_GETLINE,(WPARAM)1,(LPARAM)&TempNota);
                           SendMessage((HWND)InscInput,(UINT)EM_GETLINE,(WPARAM)1,(LPARAM)new_cand.insc);
                           if(atoi(TempNota)>100){MessageBox (NULL, "Nota deve ser\nmenor que 100","ERRO" , MB_OK);}
                           else{
                           new_cand.nota = atoi(TempNota);
                           Tamanho ++;
                           if(vazia(lista) || Cel->prox == NULL)
                           {
                                  insere(new_cand, &lista);
                                  MessageBox (NULL, "Sucesso!","Inseriu no Fim" , MB_OK);
                           }
                           else{
                                 while(Cel->prox != NULL && new_cand.nota < Cel->prox->candidato.nota)
                                           Cel = Cel -> prox;
                                           if(Cel->prox == NULL)
                                           {
                                                        insere(new_cand, &lista);
                                                        MessageBox (NULL, "Sucesso!","Inseriu no Fim" , MB_OK);
                                           }
                                           else{
                                                        insere_meio(new_cand, Cel);
                                                        MessageBox (NULL, "Inseriu no Meio", "Mensagem", MB_OK);
                                           }
                                           
                                 }
                           id++;
                           Cel = lista.primeiro;
                           }
                       break;
                       case BUTTONCOM:
                       SendMessage((HWND)VagasInput,(UINT)EM_GETLINE,(WPARAM)1,(LPARAM)&vagas);
                       Vagas = atoi(vagas);
                       if(Vagas <= 0){MessageBox (NULL, "Numero inválido de Vagas", "Mensagem", MB_OK);}
                       else{
                       ListaVazia(&lista);
                       DestroyWindow(VagasInput);
                       DestroyWindow(ButtonComecar);
                       DestroyWindow(text_intro);
                       Componentes(hwnd, message, wParam, lParam, 0);
                       } 
                       break;                         
                       case FECHAR:
                            Imprime(lista, "Vestibular.txt");
                       break;
                       case CONCLUIR:
                         if(Filtro(Tamanho,Vagas))
                         {
                                 MessageBox (NULL, "Sucesso!", "Mensagem", MB_OK);
                         }
                         else
                         {
                                 MessageBox (NULL, "Não Existe Cadastro", "Mensagem", MB_OK);
                         }
                       
                       break;
                }
             }

                switch(wParam)
                {
                       case NOVO:
                        Componentes(hwnd, message, wParam, lParam, 1);
                        return(0);
                break;
                       case ABRIR:
                break;
                       case SALVAR:
                break;
                       case SAIR:
                       PostQuitMessage(0);
                break;
                      case SOBRE:
                      MessageBox (NULL, "Luis Carlos L. Medeiros\nNicolas Ives", "Alunos", MB_OK);
                break;
                       default:
                       return(0);
                break;
                }
        break;
    //============================================
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;

        case WM_PAINT:
            hdc = BeginPaint (hwnd, &ps);
            GetClientRect (hwnd, &rc);
            DrawText (hdc, "Controle Vestibular", -1, &rc,
            DT_SINGLELINE);
        break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}

