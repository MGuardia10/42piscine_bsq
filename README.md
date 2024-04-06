# 42piscine_bsq

42 Piscine final project. BSQ aims to find the largest possible square within a map with obstacles and empty spaces.

![C](https://img.shields.io/badge/C-a?style=for-the-badge&logo=C&color=grey)

You can see the subject [**HERE.**](https://github.com/MGuardia10/42cursus/blob/main/subjects/en/bsq_subject_en.pdf)

## Preview
![d710717e-f2d9-4111-a0ab-c3e10813b422](https://github.com/MGuardia10/42piscine_bsq/assets/105164870/5be99878-c7c4-40e7-9c25-1f13d0de6ef2)

## Installing and running the project:

1- Clone this repository
	
	git clone https://github.com/MGuardia10/42pisicine_bsq.git
2- Navigate to the new directory and run `make`
	
	cd 42piscine_bsq
   	make
3- Start the program by passing some maps to it, you can find a lot in maps directory:

	./bsq <path_to_map> <path_to_map> <path_to_map> ...
If you want to try more maps, you can create new ones using `gen_map.pl` script.
  
    perl gen_map.pl [LEN_LINES] [NBR_LINES] [DENSITY] > <new_file>

## Compiling the Program
The bsq program comes with a Makefile that includes the following rules:

- `all`: compiles the program.
- `re`: recompiles the program.
- `clean`: removes obj directory with objects files.
- `fclean`: removes obj directory with objects files and bsq binary.

## Disclaimer
> At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](https://github.com/MGuardia10/42cursus/blob/main/subjects/en/norm_en.pdf), the school's coding standard. As a result, the implementation of certain parts may appear strange and for sure had room for improvement.
