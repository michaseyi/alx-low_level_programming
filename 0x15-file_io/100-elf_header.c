#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


/**
 * create_error - Prints out an error message to the standard error
 * @type: exit status of the error
 * @filename: The filename
 * @fd: file descriptor of the opened file
 * Return: void
 */

void create_error(int type, char *filename, int fd)
{
	switch (type)
	{
	case 97:
		dprintf(STDERR_FILENO, "Usage: elf_header elf_file\n");
		exit(type);
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't open %s\n", filename);
		exit(type);
	case 99:
		dprintf(STDERR_FILENO, "Error: %s is not a vaild elf file\n", filename);
		exit(type);
	case 100:
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", filename);
		exit(type);
	case 101:
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(type);
	}
}

/**
 * elf_valid - Checks if a file is an ELF format
 * @header: first 16 bytes of the file
 * Return: 1 if it is an ELF file else 0
 */

int elf_valid(unsigned char *header)
{
	int ret_val;

	ret_val = (header[0] == 0x7f) && (header[1] == 'E') && 
				(header[2] == 'L') && (header[3] == 'F');
	return (ret_val);
}

/**
 * print_magic - Prints the magic number of an ELF header file
 * @e_ident: Pointer to the first 16 bytes of the ELF header
 */

void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		if (i < EI_NIDENT - 1)
			printf("%02x ", e_ident[i]);
		else
			printf("%02x\n", e_ident[i]);
	}
}

/**
 * print_class -  Prints the class of an ELF header
 * @e_ident: Pointer to the first 16 bytes of the ELF header
 */

void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data of an ELF header file
 * @e_ident: Pointer to the first 16 bytes of the ELF header
 */

void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - Prints the version of an ELF header file
 * @e_ident: Pointer to the first 16 bytes of the ELF header
 */

void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			 e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints the osabi of an ELF header file
 * @e_ident: Pointer to the first 16 bytes of the ELF header
 */

void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the abi of an ELF header file
 * @e_ident: The first 16 bytes of the ELF header file
 */

void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			 e_ident[EI_ABIVERSION]);
}


/**
 * print_type - Prints the type of an ELF header file
 * @e_type: The type of ELF file
 * @e_ident: The first 16 bytes of the ELF header file
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry of an ELF header file
 * @e_entry: The entry point address of an ELF file
 * @e_ident: The first 16 bytes of the ELF header file
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
					 ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_file - Closes an open file
 * @fd: file descriptor of the open file
 */

void close_file(int fd)
{
	if (close(fd) == -1)
		create_error(101, NULL, fd);
}

/**
 * main - Displays the ELF header info of an ELF file
 * @argc: Number of command line argument
 * @argv: Array of command line argument
 * Return: 0
 */

int main(int argc, char *argv[])
{
	Elf64_Ehdr header;
	int fd, read_ret;

	if (argc != 2)
		create_error(97, NULL, -1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		create_error(98, argv[1], -1);
	read_ret = read(fd, &header, sizeof(Elf64_Ehdr));
	if (read_ret == -1)
	{
		close_file(fd);
		create_error(100, argv[1], -1);
	}

	if (!elf_valid(header.e_ident))
		create_error(99, argv[1], -1);
	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abi(header.e_ident);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);
	close_file(fd);
	return (0);
}
