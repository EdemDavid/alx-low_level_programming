#include <elf.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define REVIT(p) ((p << 24) | (((p >> 16) << 24) >> 16) | \
(((p << 16) >> 24) << 16) | (p >> 24))

/**
* confirm - Checks if file is a ELF
* @id_byte: ELF struct
* Return: 0
*/

void confirm(unsigned char *id_byte)
{
	if (*(id_byte) == 0x7f && *(id_byte + 1) == 'E' &&
	    *(id_byte + 2) == 'L' && *(id_byte + 3) == 'F')
	{
		printf("ELF Header:\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: this file not is a valid ELF\n");
		exit(98);
	}
}

/**
* abra - Prints magical number
* @id_byte: ELF struct
* Return: 0
*/

void abra(unsigned char *id_byte)
{
	int a;
	int lim;

	lim = EI_NIDENT - 1;
	printf("  Magic:   ");
	for (a = 0; a < lim; a++)
		printf("%02x ", *(id_byte + a));
	printf("%02x\n", *(id_byte + a));
}

/**
* level - Prints the ELF class
* @id_byte: ELF struct
* Return: 0
*/

void level(unsigned char *id_byte)
{
	printf("  Class:                             ");
	if (id_byte[EI_CLASS] == ELFCLASSNONE)
		printf("This class is invalid\n");
	else if (id_byte[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (id_byte[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", id_byte[EI_CLASS]);
}

/**
* type - Prints the respective data type
* @id_byte: ELF struct
* Return: 0
*/

void type(unsigned char *id_byte)
{
	printf("  Data:                              ");
	if (id_byte[EI_DATA] == ELFDATANONE)
		printf("Unknown data format\n");
	else if (id_byte[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (id_byte[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", id_byte[EI_DATA]);
}

/**
* design - Prints the file version
* @id_byte: ELF struct
* Return: 0
*/

void design(unsigned char *id_byte)
{
	printf("  Version:                           ");
	if (id_byte[EI_VERSION] == EV_CURRENT)
		printf("%i (current)\n", EV_CURRENT);
	else
		printf("%i\n", id_byte[EI_VERSION]);
}

/**
 * bin_int - Prints the OSABI
 * @id_byte: ELF struct
 * Return: 0
 */

void bin_int(unsigned char *id_byte)
{
	printf("  OS/ABI:                            ");
	if (id_byte[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (id_byte[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (id_byte[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (id_byte[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (id_byte[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (id_byte[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (id_byte[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (id_byte[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (id_byte[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (id_byte[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", id_byte[EI_OSABI]);
}

/**
* dtype - Prints the respective type
* @id_byte: ELF struct
* @e_type: Data to be compared and printed
* Return: 0
*/

void dtype(unsigned int e_type, unsigned char *id_byte)
{
	id_byte[EI_DATA] == ELFDATA2MSB ? e_type = e_type >> 8 : e_type;

	printf("  Type:                              ");
	if (e_type == ET_NONE)
		printf("NONE (Unknown type)\n");
	else if (e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", e_type);
}

/**
* ent - Prints the point of entry
* @id_byte: ELF struct
* @e_entry: Data to be printed
* Return: 0
*/

void ent(unsigned int e_entry, unsigned char *id_byte)
{
	if (id_byte[EI_DATA] == ELFDATA2MSB)
		e_entry = REVIT(e_entry);

	printf("  Entry point address:               ");
	printf("%#x\n", (unsigned int)e_entry);
}

/**
* main - Reads ELF
* @argc: Argument number
* @argv: Argument
* Return: 0
*/

int main(int argc, char *argv[])
{
	int fd, re, cl;
	Elf64_Ehdr *file;

	if (argc > 2 || argc < 2)
		dprintf(STDERR_FILENO, "Usage: error in # of args\n"), exit(98);
	file = malloc(sizeof(Elf64_Ehdr));
	if (file == NULL)
		dprintf(STDERR_FILENO, "error in allocate memory\n"), exit(98);
	fd = open(*(argv + 1), O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	re = read(fd, file, sizeof(Elf64_Ehdr));
	if (re == -1)
	{
		free(file);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	confirm(file->e_ident);
	abra(file->e_ident);
	level(file->e_ident);
	type(file->e_ident);
	design(file->e_ident);
	bin_int(file->e_ident);
	printf("  ABI Version:                       ");
	printf("%i\n", file->e_ident[EI_ABIVERSION]);
	dtype(file->e_type, file->e_ident);
	ent(file->e_entry, file->e_ident);
	free(file);
	cl = close(fd);
	if (cl)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(98);
	}
	return (0);
}
