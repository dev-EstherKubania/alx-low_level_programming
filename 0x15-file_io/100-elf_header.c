#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - entry point
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
        int fd;
        Elf64_Ehdr header;
        ssize_t num_bytes_read;
        int i;

        if (argc != 2)
        {
                fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
                exit(98);
        }
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
                fprintf(stderr, "Error: failed to open file '%s'\n", argv[1]);
                exit(98);
        }
        num_bytes_read = read(fd, &header, sizeof(header));
        if (num_bytes_read < 0)
        {
                fprintf(stderr, "Error: failed to read ELF header from file '%s'\n", argv[1]);
                exit(98);
        }
        if (header.e_ident[EI_MAG0] != ELFMAG0 ||
            header.e_ident[EI_MAG1] != ELFMAG1 ||
            header.e_ident[EI_MAG2] != ELFMAG2 ||
            header.e_ident[EI_MAG3] != ELFMAG3)
        {
                fprintf(stderr, "Error: file '%s' is not an ELF file\n", argv[1]);
                exit(98);
        }
        printf("Magic: ");
        for (i = 0; i < EI_NIDENT; i++)
        {
                printf("%02x ", header.e_ident[i]);
        }
        printf("\n");
        printf("Class: ");
        switch (header.e_ident[EI_CLASS])
        {
                case ELFCLASS32:
                        printf("ELF32\n");
                        break;
                case ELFCLASS64:
                        printf("ELF64\n");
                        break;
                default:
                        printf("Invalid\n");
                        break;
        }
        printf("Data: ");
        switch (header.e_ident[EI_DATA])
        {
                case ELFDATA2LSB:
                        printf("2's complement, little endian\n");
                        break;
                case ELFDATA2MSB:
                        printf("2's complement, big endian\n");
                        break;
                default:
                        printf("Invalid\n");
                        break;
        }
        printf("Version: %d\n", header.e_ident[EI_VERSION]);
        printf("OS/ABI: ");
        switch (header.e_ident[EI_OSABI])
        {
                case ELFOSABI_SYSV:
                        printf("UNIX System V ABI\n");
                        break;
                case ELFOSABI_HPUX:
                        printf("HP-UX ABI\n");
                        break;
                case ELFOSABI_NETBSD:
                        printf("NetBSD ABI\n");
                        break;
                case ELFOSABI_LINUX:
                        printf("Linux ABI\n");
                        break;
                case ELFOSABI_SOLARIS:
                        printf("Solaris ABI\n");
                        break;
                case ELFOSABI_AIX:
                        printf("AIX ABI\n");
                        break;
                case ELFOSABI_IRIX:
                        printf("IRIX ABI\n");
                        break;
                case ELFOSABI_FREEBSD:
                        printf("FreeBSD ABI\n");
                        break;
                case ELFOSABI_OPENBSD:
                        printf("OpenBSD ABI\n");
                        break;
                default:
                        printf("Other ABI\n");
                        break;
        }
	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	return (0);
}

