#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"

int main(int argc, char*argv[]){
    	char buf[520];
	int file, dir,n;
	if(argc < 3){
		printf(1,"Tambahkan lagi argumen\n");
		exit();
	}
	
	if((file = open(argv[1],O_RDONLY)) < 0){
		printf(1,"file belum dibuat\n");
		exit();
	}
	
	if((dir = open(argv[2],O_CREATE | O_WRONLY)) < 0){
		printf(1,"Direktori yang dituju belum ada\n");
		exit();
	}
	while((n = read(file, buf, sizeof(buf))) > 0){
		write(dir, buf, sizeof(buf));
	}

	close(file);
	close(dir);
	unlink(argv[1]);
	exit();
}
