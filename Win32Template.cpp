#include<windows.h>
#include"resource.h"

LRESULT CALLBACK wndProc( HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow )
{
	TCHAR szAppName[]	= TEXT("iconDemo" );
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= wndProc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon( hInstance, MAKEINTRESOURCE( IDI_DEMO ) );
	wndclass.hCursor		= LoadCursor( NULL, IDC_ARROW );
	wndclass.hbrBackground	= (HBRUSH)GetStockObject( WHITE_BRUSH );
	wndclass.lpszClassName	= szAppName;
	wndclass.lpszMenuName	= NULL;

	if( !RegisterClass( &wndclass ) ){
		MessageBox( NULL, TEXT("Sorry, there's something wrong" ), szAppName, MB_ICONERROR );
		return 0;
	}

	hwnd = CreateWindow( szAppName, TEXT("MyApplication"),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT,
			NULL, NULL, hInstance, NULL );

	ShowWindow( hwnd, iCmdShow );
	UpdateWindow( hwnd );

	while( GetMessage( &msg, NULL, 0, 0 ) ){
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	return msg.wParam;
}


LRESULT CALLBACK wndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch( message ){
		case WM_CREATE:
			return 0;
		case WM_SIZE:
			return 0;
		case WM_PAINT:
			hdc = BeginPaint( hwnd, &ps );

			EndPaint( hwnd, &ps );
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	
	return DefWindowProc( hwnd, message, wParam, lParam );
}


