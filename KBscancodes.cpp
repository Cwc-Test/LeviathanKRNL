#include "typedefs.cpp"
#include "printf.cpp"

bool ShiftPressed = false;
uint_8 LastScancode;

void StandardKeyboardHandler(uint8 scancodes, uint8 chr){
    if (chr != 0){
        switch (ShiftPressed) {
        
        case true:
            printchar(chr - 32);
            break;
        case false:
            printchar(chr);
            break;
        }
    }else{
        switch (scancodes) {
            if (ProtectedPoz[CursorPosition] == 0){
                case 0x0E: //backspace
                    SetCursorPosition(CursorPosition - 1);
	    		    printchar(' ');
	    		    SetCursorPosition(CursorPosition - 1);
                 break;
	          	case 0x2A: //Left Shift
	        		ShiftPressed = true;
	    	    	break;
	    	    case 0xAA: //Left Shift Released
          			ShiftPressed = false;
          		case 0x36: //Right Shift
          			ShiftPressed = true;
          			break;
         		case 0xB6: //Right Shift Released
         			ShiftPressed = false;
         			break;
                 case 0x1C: //enter
                     printf("\n");
                     break;
                 // numpad
                 case 0x52:
                     printf(IntToStr(0));
                     break;
                 case 0x4F:
                     printf(IntToStr(1));
                     break;
                 case 0x50:
                     printf(IntToStr(2));
                     break;
                 case 0x51:
                     printf(IntToStr(3));
                     break;
                 case 0x4B:
                     printf(IntToStr(4));
                     break;
                 case 0x4C:
                     printf(IntToStr(5));
                     break;
                 case 0x4D:
                     printf(IntToStr(6));
                     break;
                 case 0x47:
                     printf(IntToStr(7));
                     break;
                 case 0x48:
                     printf(IntToStr(8));
                     break;
                 case 0x49:
                     printf(IntToStr(9));
                     break;
                case 0x4A:
                      printf("-");
                      break;
                case 0x4E:
                      printf("+");
                      break;
                case 0x53:
                      printf(".");
                      break;
                case 0x2B:
                      printf("/");
                      break;
            }
        }
    }
}

void KeyboardHandler0xE0(uint_8 scanCode) {
	switch (scanCode)
	{
	case 0x50:
		SetCursorPosition(CursorPosition + VGA_WIDTH);
		break;
	case 0x48:
		SetCursorPosition(CursorPosition - VGA_WIDTH);
		break;
    case 0x4B:
        SetCursorPosition(CursorPosition -1);
        break;
    case 0x4D:
        SetCursorPosition(CursorPosition +1);
        break;
    case 0x35:
        printf("/");
        break;
    case 0x5E:
        printf("Do Not PRESS SHUT DOWN BUTTON!!!");
        break;
    case 0x1C: //enter
        printf("\n");
        break;
	}
}

void Keyboardhandler(uint8 scancodes, uint8 chr){
    	switch (LastScancode) {
        	case 0xE0:
		        KeyboardHandler0xE0(scancodes);
		        break;
          	default:
	        	StandardKeyboardHandler(scancodes, chr);
	}

	LastScancode = scancodes;
}
