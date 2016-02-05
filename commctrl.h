
#pragma once

#include "windows.h"

typedef void *HWND;
typedef void *HINSTANCE;
typedef void *HIMAGELIST;
typedef void *HICON;
typedef void *HBITMAP;
typedef void *NMHDR;
typedef void *LRESULT;
typedef void *WPARAM;
typedef void *LPARAM;

#define CALLBACK

void InitCommonControls();

#define MB_OK  0
#define MB_ICONINFORMATION 0
#define MB_ICONERROR 0

typedef void* MSG;
typedef MSG *LPMSG;

BOOL WINAPI GetMessage(
  _Out_    LPMSG lpMsg,
  _In_opt_ HWND  hWnd,
  _In_     UINT  wMsgFilterMin,
  _In_     UINT  wMsgFilterMax
);

int _CrtSetDbgFlag( 
  int newFlag 
);

int WINAPI MessageBox(
  _In_opt_ HWND    hWnd,
  _In_opt_ LPCTSTR lpText,
  _In_opt_ LPCTSTR lpCaption,
  _In_     UINT    uType
);

BOOL WINAPI IsDialogMessage(
  _In_ HWND  hDlg,
  _In_ LPMSG lpMsg
);

BOOL WINAPI TranslateMessage(
  _In_ const MSG *lpMsg
);

LRESULT WINAPI DispatchMessage(
  _In_ const MSG *lpmsg
);

