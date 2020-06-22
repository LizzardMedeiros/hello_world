#define NOVO_MENU 555

#define BUTTONOK 10
#define CONCLUIR 20
#define FECHAR 30
#define BUTTONCOM 40

//Aba Arquivo

#define NOVO         100
#define ABRIR        101
#define SALVAR        102
#define SALVAR_COMO      103
#define IMPRIMIR       104
#define CONFIGURAR_PAGINA   105
#define CONFIGURAR_IMPRESSAO  106
#define SAIR        107

//Aba Editar

#define VOLTAR        110
#define CORTAR         111
#define COPIAR        112
#define COLAR       113
#define DELETAR      114

//Aba Ajuda

#define SOBRE    120
HINSTANCE g_inst;
HWND NomeInput, InscInput, NotaInput, ButtonOk, ButtonComecar, VagasInput, text_intro;
    
void Componentes(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, int opcao)
{

//=======================================================
switch (opcao)
{
       case 0:
            CreateWindowEx (
            0,
            "STATIC",
            "Nome",
            WS_VISIBLE|WS_CHILD,
            30, 70, 100, 20,
            hwnd,
            NULL,
            g_inst,
            NULL
            );

            NomeInput = CreateWindowEx (
            WS_EX_CLIENTEDGE,
            "EDIT",
            "",
            WS_VISIBLE|WS_CHILD,
            130, 70, 250, 20,
            hwnd,
            NULL,
            g_inst,
            NULL
            );
            
            CreateWindowEx (
            0,
            "STATIC",
            "Inscrição",
            WS_VISIBLE|WS_CHILD,
            30, 100, 100, 20,
            hwnd,
            NULL,
            g_inst,
            NULL
            );
            
            InscInput = CreateWindowEx (
            WS_EX_CLIENTEDGE,
            "EDIT",
            "",
            WS_VISIBLE|WS_CHILD,
            130,100,100,20,
            hwnd,
            NULL,
            g_inst,
            NULL
            );
            
            CreateWindowEx (
            0,
            "STATIC",
            "Nota",
            WS_VISIBLE|WS_CHILD,
            30, 130, 100, 20,
            hwnd,
            NULL,
            g_inst,
            NULL
            );
            
            NotaInput = CreateWindowEx (
            WS_EX_CLIENTEDGE,
            "EDIT",
            "",
            WS_VISIBLE|WS_CHILD,
            130,130,50,20,
            hwnd,
            NULL,
            g_inst,
            NULL
            );           
            
            ButtonOk = CreateWindowEx (
            0,
            "BUTTON",
            "Cadastrar",
            WS_VISIBLE|WS_CHILD,
            30, 190, 80, 40,
            hwnd,
            (HMENU)BUTTONOK,
            g_inst,
            NULL
            );
            
            CreateWindowEx (
            0,
            "BUTTON",
            "Fechar Lista",
            WS_VISIBLE|WS_CHILD,
            110, 190, 100, 40,
            hwnd,
            (HMENU)FECHAR,
            g_inst,
            NULL
            );
            
            CreateWindowEx (
            0,
            "BUTTON",
            "Concluir",
            WS_VISIBLE|WS_CHILD,
            210, 190, 80, 40,
            hwnd,
            (HMENU)CONCLUIR,
            g_inst,
            NULL
            );
            
       break;
       case 1:
            text_intro = CreateWindowEx (
            0,
            "STATIC",
            "Número de Vagas",
            WS_VISIBLE|WS_CHILD,
            30, 70, 80, 40,
            hwnd,
            NULL,
            g_inst,
            NULL
            );
            
            VagasInput = CreateWindowEx (
            WS_EX_CLIENTEDGE,
            "EDIT",
            "",
            WS_VISIBLE|WS_CHILD,
            130, 70, 40, 20,
            hwnd,
            NULL,
            g_inst,
            NULL
            );
            
            ButtonComecar = CreateWindowEx (
            0,
            "BUTTON",
            "OK",
            WS_VISIBLE|WS_CHILD,
            30, 110, 80, 40,
            hwnd,
            (HMENU)BUTTONCOM,
            g_inst,
            NULL
            );
            break;
       default:
               MessageBox(hwnd,"Erro","C++",0);
       break;
}
}


