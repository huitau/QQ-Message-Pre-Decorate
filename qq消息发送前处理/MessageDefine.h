#pragma once



// WM_KEYBOARD_HOOK_FIRST �б�ǲ������CallNextHookEx
#define KHF_DONOT_CALLNEXTHOOKEX		0x00000001
// WM_KEYBOARD_HOOK_FIRST �б�������PostMessage������WM_KEYBOARD_HOOK_NEXT��Ϣ
#define KHF_POSTNEXTMESSAGE		0x00000002

#define WM_KEYBOARD_HOOK_FIRST			WM_USER + 1









#define WM_KEYBOARD_HOOK_NEXT			WM_USER + 2