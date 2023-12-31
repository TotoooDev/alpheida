#ifndef KEYBOARD_H
#define KEYBOARD_H

// i'm not really in the mood to write (or rather copy-paste) every keycode for every platform
// so these are the scancodes just for sdl
// good luck trying to work with that on other platforms lol
// more info on https://github.com/libsdl-org/SDL/blob/SDL2/include/SDL_scancode.h

#define SHRIMP_KEY_UNKNOWN 0

#define SHRIMP_KEY_A 4
#define SHRIMP_KEY_B 5
#define SHRIMP_KEY_C 6
#define SHRIMP_KEY_D 7
#define SHRIMP_KEY_E 8
#define SHRIMP_KEY_F 9
#define SHRIMP_KEY_G 10
#define SHRIMP_KEY_H 11
#define SHRIMP_KEY_I 12
#define SHRIMP_KEY_J 13
#define SHRIMP_KEY_K 14
#define SHRIMP_KEY_L 15
#define SHRIMP_KEY_M 16
#define SHRIMP_KEY_N 17
#define SHRIMP_KEY_O 18
#define SHRIMP_KEY_P 19
#define SHRIMP_KEY_Q 20
#define SHRIMP_KEY_R 21
#define SHRIMP_KEY_S 22
#define SHRIMP_KEY_T 23
#define SHRIMP_KEY_U 24
#define SHRIMP_KEY_V 25
#define SHRIMP_KEY_W 26
#define SHRIMP_KEY_X 27
#define SHRIMP_KEY_Y 28
#define SHRIMP_KEY_Z 29
#define SHRIMP_KEY_1 30
#define SHRIMP_KEY_2 31
#define SHRIMP_KEY_3 32
#define SHRIMP_KEY_4 33
#define SHRIMP_KEY_5 34
#define SHRIMP_KEY_6 35
#define SHRIMP_KEY_7 36
#define SHRIMP_KEY_8 37
#define SHRIMP_KEY_9 38
#define SHRIMP_KEY_0 39
#define SHRIMP_KEY_RETURN 40
#define SHRIMP_KEY_ESCAPE 41
#define SHRIMP_KEY_BACKSPACE 42
#define SHRIMP_KEY_TAB 43
#define SHRIMP_KEY_SPACE 44
#define SHRIMP_KEY_MINUS 45
#define SHRIMP_KEY_EQUALS 46
#define SHRIMP_KEY_LEFTBRACKET 47
#define SHRIMP_KEY_RIGHTBRACKET 48
#define SHRIMP_KEY_BACKSLASH 49
#define SHRIMP_KEY_NONUSHASH 50
#define SHRIMP_KEY_SEMICOLON 51
#define SHRIMP_KEY_APOSTROPHE 52
#define SHRIMP_KEY_GRAVE 53
#define SHRIMP_KEY_COMMA 54
#define SHRIMP_KEY_PERIOD 55
#define SHRIMP_KEY_SLASH 56
#define SHRIMP_KEY_CAPSLOCK 57
#define SHRIMP_KEY_F1 58
#define SHRIMP_KEY_F2 59
#define SHRIMP_KEY_F3 60
#define SHRIMP_KEY_F4 61
#define SHRIMP_KEY_F5 62
#define SHRIMP_KEY_F6 63
#define SHRIMP_KEY_F7 64
#define SHRIMP_KEY_F8 65
#define SHRIMP_KEY_F9 66
#define SHRIMP_KEY_F10 67
#define SHRIMP_KEY_F11 68
#define SHRIMP_KEY_F12 69
#define SHRIMP_KEY_PRINTSCREEN 70
#define SHRIMP_KEY_SCROLLLOCK 71
#define SHRIMP_KEY_PAUSE 72
#define SHRIMP_KEY_INSERT 73
#define SHRIMP_KEY_HOME 74
#define SHRIMP_KEY_PAGEUP 75
#define SHRIMP_KEY_DELETE 76
#define SHRIMP_KEY_END 77
#define SHRIMP_KEY_PAGEDOWN 78
#define SHRIMP_KEY_RIGHT 79
#define SHRIMP_KEY_LEFT 80
#define SHRIMP_KEY_DOWN 81
#define SHRIMP_KEY_UP 82
#define SHRIMP_KEY_NUMLOCKCLEAR 83
#define SHRIMP_KEY_KP_DIVIDE 84
#define SHRIMP_KEY_KP_MULTIPLY 85
#define SHRIMP_KEY_KP_MINUS 86
#define SHRIMP_KEY_KP_PLUS 87
#define SHRIMP_KEY_KP_ENTER 88
#define SHRIMP_KEY_KP_1 89
#define SHRIMP_KEY_KP_2 90
#define SHRIMP_KEY_KP_3 91
#define SHRIMP_KEY_KP_4 92
#define SHRIMP_KEY_KP_5 93
#define SHRIMP_KEY_KP_6 94
#define SHRIMP_KEY_KP_7 95
#define SHRIMP_KEY_KP_8 96
#define SHRIMP_KEY_KP_9 97
#define SHRIMP_KEY_KP_0 98
#define SHRIMP_KEY_KP_PERIOD 99
#define SHRIMP_KEY_NONUSBACKSLASH 100
#define SHRIMP_KEY_APPLICATION 101
#define SHRIMP_KEY_POWER 102
#define SHRIMP_KEY_KP_EQUALS 103
#define SHRIMP_KEY_F13 104
#define SHRIMP_KEY_F14 105
#define SHRIMP_KEY_F15 106
#define SHRIMP_KEY_F16 107
#define SHRIMP_KEY_F17 108
#define SHRIMP_KEY_F18 109
#define SHRIMP_KEY_F19 110
#define SHRIMP_KEY_F20 111
#define SHRIMP_KEY_F21 112
#define SHRIMP_KEY_F22 113
#define SHRIMP_KEY_F23 114
#define SHRIMP_KEY_F24 115
#define SHRIMP_KEY_EXECUTE 116
#define SHRIMP_KEY_HELP 117
#define SHRIMP_KEY_MENU 118
#define SHRIMP_KEY_SELECT 119
#define SHRIMP_KEY_STOP 120
#define SHRIMP_KEY_AGAIN 121
#define SHRIMP_KEY_UNDO 122
#define SHRIMP_KEY_CUT 123
#define SHRIMP_KEY_COPY 124
#define SHRIMP_KEY_PASTE 125
#define SHRIMP_KEY_FIND 126
#define SHRIMP_KEY_MUTE 127
#define SHRIMP_KEY_VOLUMEUP 128
#define SHRIMP_KEY_VOLUMEDOWN 129
#define SHRIMP_KEY_LOCKINGCAPSLOCK 130 
#define SHRIMP_KEY_LOCKINGNUMLOCK 131
#define SHRIMP_KEY_LOCKINGSCROLLLOCK 132
#define SHRIMP_KEY_KP_COMMA 133
#define SHRIMP_KEY_KP_EQUALSAS400 134
#define SHRIMP_KEY_INTERNATIONAL1 135
#define SHRIMP_KEY_INTERNATIONAL2 136
#define SHRIMP_KEY_INTERNATIONAL3 137
#define SHRIMP_KEY_INTERNATIONAL4 138
#define SHRIMP_KEY_INTERNATIONAL5 139
#define SHRIMP_KEY_INTERNATIONAL6 140
#define SHRIMP_KEY_INTERNATIONAL7 141
#define SHRIMP_KEY_INTERNATIONAL8 142
#define SHRIMP_KEY_INTERNATIONAL9 143
#define SHRIMP_KEY_LANG1 144
#define SHRIMP_KEY_LANG2 145
#define SHRIMP_KEY_LANG3 146 
#define SHRIMP_KEY_LANG4 147 
#define SHRIMP_KEY_LANG5 148
#define SHRIMP_KEY_LANG6 149 
#define SHRIMP_KEY_LANG7 150 
#define SHRIMP_KEY_LANG8 151 
#define SHRIMP_KEY_LANG9 152 
#define SHRIMP_KEY_ALTERASE 153
#define SHRIMP_KEY_SYSREQ 154
#define SHRIMP_KEY_CANCEL 155 
#define SHRIMP_KEY_CLEAR 156
#define SHRIMP_KEY_PRIOR 157
#define SHRIMP_KEY_RETURN2 158
#define SHRIMP_KEY_SEPARATOR 159
#define SHRIMP_KEY_OUT 160
#define SHRIMP_KEY_OPER 161
#define SHRIMP_KEY_CLEARAGAIN 162
#define SHRIMP_KEY_CRSEL 163
#define SHRIMP_KEY_EXSEL 164
#define SHRIMP_KEY_KP_00 176
#define SHRIMP_KEY_KP_000 177
#define SHRIMP_KEY_THOUSANDSSEPARATOR 178
#define SHRIMP_KEY_DECIMALSEPARATOR 179
#define SHRIMP_KEY_CURRENCYUNIT 180
#define SHRIMP_KEY_CURRENCYSUBUNIT 181
#define SHRIMP_KEY_KP_LEFTPAREN 182
#define SHRIMP_KEY_KP_RIGHTPAREN 183
#define SHRIMP_KEY_KP_LEFTBRACE 184
#define SHRIMP_KEY_KP_RIGHTBRACE 185
#define SHRIMP_KEY_KP_TAB 186
#define SHRIMP_KEY_KP_BACKSPACE 187
#define SHRIMP_KEY_KP_A 188
#define SHRIMP_KEY_KP_B 189
#define SHRIMP_KEY_KP_C 190
#define SHRIMP_KEY_KP_D 191
#define SHRIMP_KEY_KP_E 192
#define SHRIMP_KEY_KP_F 193
#define SHRIMP_KEY_KP_XOR 194
#define SHRIMP_KEY_KP_POWER 195
#define SHRIMP_KEY_KP_PERCENT 196
#define SHRIMP_KEY_KP_LESS 197
#define SHRIMP_KEY_KP_GREATER 198
#define SHRIMP_KEY_KP_AMPERSAND 199
#define SHRIMP_KEY_KP_DBLAMPERSAND 200
#define SHRIMP_KEY_KP_VERTICALBAR 201
#define SHRIMP_KEY_KP_DBLVERTICALBAR 202
#define SHRIMP_KEY_KP_COLON 203
#define SHRIMP_KEY_KP_HASH 204
#define SHRIMP_KEY_KP_SPACE 205
#define SHRIMP_KEY_KP_AT 206
#define SHRIMP_KEY_KP_EXCLAM 207
#define SHRIMP_KEY_KP_MEMSTORE 208
#define SHRIMP_KEY_KP_MEMRECALL 209
#define SHRIMP_KEY_KP_MEMCLEAR 210
#define SHRIMP_KEY_KP_MEMADD 211
#define SHRIMP_KEY_KP_MEMSUBTRACT 212
#define SHRIMP_KEY_KP_MEMMULTIPLY 213
#define SHRIMP_KEY_KP_MEMDIVIDE 214
#define SHRIMP_KEY_KP_PLUSMINUS 215
#define SHRIMP_KEY_KP_CLEAR 216
#define SHRIMP_KEY_KP_CLEARENTRY 217
#define SHRIMP_KEY_KP_BINARY 218
#define SHRIMP_KEY_KP_OCTAL 219
#define SHRIMP_KEY_KP_DECIMAL 220
#define SHRIMP_KEY_KP_HEXADECIMAL 221
#define SHRIMP_KEY_LCTRL 224
#define SHRIMP_KEY_LSHIFT 225
#define SHRIMP_KEY_LALT 226
#define SHRIMP_KEY_LGUI 227
#define SHRIMP_KEY_RCTRL 228
#define SHRIMP_KEY_RSHIFT 229
#define SHRIMP_KEY_RALT 230
#define SHRIMP_KEY_RGUI 231
#define SHRIMP_KEY_AUDIONEXT 258
#define SHRIMP_KEY_AUDIOPREV 259
#define SHRIMP_KEY_AUDIOSTOP 260
#define SHRIMP_KEY_AUDIOPLAY 261
#define SHRIMP_KEY_AUDIOMUTE 262
#define SHRIMP_KEY_MEDIASELECT 263
#define SHRIMP_KEY_WWW 264
#define SHRIMP_KEY_MAIL 265
#define SHRIMP_KEY_CALCULATOR 266    
#define SHRIMP_KEY_COMPUTER 267
#define SHRIMP_KEY_AC_SEARCH 268       
#define SHRIMP_KEY_AC_HOME 269         
#define SHRIMP_KEY_AC_BACK 270         
#define SHRIMP_KEY_AC_FORWARD 271      
#define SHRIMP_KEY_AC_STOP 272         
#define SHRIMP_KEY_AC_REFRESH 273      
#define SHRIMP_KEY_AC_BOOKMARKS 274    
#define SHRIMP_KEY_BRIGHTNESSDOWN 275
#define SHRIMP_KEY_BRIGHTNESSUP 276
#define SHRIMP_KEY_DISPLAYSWITCH 277
#define SHRIMP_KEY_KBDILLUMTOGGLE 278
#define SHRIMP_KEY_KBDILLUMDOWN 279
#define SHRIMP_KEY_KBDILLUMUP 280
#define SHRIMP_KEY_EJECT 281
#define SHRIMP_KEY_SLEEP 282 
#define SHRIMP_KEY_APP1 283
#define SHRIMP_KEY_APP2 284
#define SHRIMP_KEY_AUDIOREWIND 285
#define SHRIMP_KEY_AUDIOFASTFORWARD 286
#define SHRIMP_KEY_SOFTLEFT 287
#define SHRIMP_KEY_SOFTRIGHT 288
#define SHRIMP_KEY_CALL 289
#define SHRIMP_KEY_ENDCALL 290

#endif
