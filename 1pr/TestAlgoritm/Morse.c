#include <stdio.h>

void blinkCode(char code){
	int codeDelay = 0;
	if (code=='-') codeDelay = 1;
	printf("%d ", codeDelay);
}

char morseAlphabet[26][5] = {
	".-",  "-...",  "-.-.",  // A B C
	"-..", ".",     "..-.",  // D E F
	"--.", "....",  "..",    // G H I
	".---", "-.-",   ".-..",  // J K L
	"--",  "-.",    "---",   // M N O
	".--.", "--.-",  ".-.",   // P Q R
	"...", "-",     "..-",   // S T U
	"...-", ".--",   "-..-",  // V W X
	"-.--", "--.."   		 // Y Z
};

int charsLen(char str[]){
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}

void morseBlink(char word[]){
	int wordLen = charsLen(word);
	for (int letterI= 0; letterI < wordLen; letterI++){
		int letterIndex = (int)word[letterI] - (int)'A';
		printf("%c \t ", word[letterI]);
		printf("%s \t", morseAlphabet[ letterIndex ]);

		// не працює char morseCode[6] = morseAlphabet[ letterIndex ];
		// printf("%s\n", morseCode);
		// нехай morseCode == morseAlphabet[letterIndex] 
		// Хз як копіювати масиви у с, тому костиль

		int morseCodeLen = charsLen(morseAlphabet[letterIndex] );
		for (int codeI= 0; codeI < morseCodeLen; codeI++)
			blinkCode(morseAlphabet[letterIndex][codeI]);
		printf("\n");
	}	
}

int main(){
	// Only UPPER_CASE letters
    char name[] = "POHORIELOV";
    morseBlink(name);
    return 0;
}

/* РЕЗУЛЬТАТ:
P 	 .--. 	0 1 1 0
O 	 --- 	1 1 1
H 	 .... 	0 0 0 0
O 	 --- 	1 1 1
R 	 .-. 	0 1 0
I 	 .. 	0 0
E 	 . 		0
L 	 .-.. 	0 1 0 0
O 	 --- 	1 1 1
V 	 ...- 	0 0 0 1
*/
