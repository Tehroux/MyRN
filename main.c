#include "matrice.h"

int main(int argc, char ** argv)
{
	Picture *pic = NULL;
	if (argc != 2) {
		printf("USAGE: %s[file]\n", argv[0]);
		return 0;
	}
	pic = pictureFromFile(argv[1]);
	displayPicture(pic);
	freePicture(pic);
	return 0;
}
