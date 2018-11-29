/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebrocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:58:17 by jebrocho          #+#    #+#             */
/*   Updated: 2018/11/29 16:00:10 by jebrocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, const char **av)
{
	int		fd, fd2, fd3, fd4, fd5, fd6, fd7;
	int		ret, ret2, ret3, ret4, ret5, ret6, ret7;
	char	*line;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	fd4 = open(av[4], O_RDONLY);
	fd5 = open(av[5], O_RDONLY);
	fd6 = open(av[6], O_RDONLY);
	fd7 = open(av[7], O_RDONLY);

	ret = 1;
	ret2 = 1;
	ret3 = 1;
	ret4 = 1;
	ret5 = 1;
	ret6 = 1;
	ret7 = 1;
//	ret = get_next_line(-1, &line);
	while (ret == 1 || ret2 == 1 || ret3 == 1|| ret4 == 1 || ret5 == 1 || ret6 == 1 || ret7 == 1)
	{
		ret = get_next_line(fd, &line);
		printf("fd : %d |>>| %s\n", ret, line);
		ret2 = get_next_line(fd2, &line);
		printf("fd2 : %d |>>| %s\n", ret2, line);
		ret3 = get_next_line(fd3, &line);
		printf("fd3 : %d |>>| %s\n", ret3, line);
		ret4 = get_next_line(fd4, &line);
		printf("fd4 : %d |>>| %s\n", ret4, line);
		ret5 = get_next_line(fd5, &line);
		printf("fd5 : %d |>>| %s\n", ret5, line);
		ret6 = get_next_line(fd6, &line);
		printf("fd6 : %d |>>| %s\n", ret6, line);
		ret7 = get_next_line(fd7, &line);
		printf("fd7 : %d |>>| %s\n", ret7, line);
		ft_strdel(&line);
	}
	close(fd);
	close(fd2);
	return (0);
}


//#define TF_DEBUG	0
/*
void	test(char *filename)
{
	int	fd;
	int	outfd;
	char	*line;
	int	returned;

	if (TF_DEBUG)
	{
		printf("===========================================================\n");
		printf("filename = %s\n", filename);
	}
	fd = open(filename, O_RDONLY);
	outfd = open("this_out.txt", O_WRONLY | O_TRUNC);
	line = NULL;
	while ((returned = get_next_line(fd, &line)) == 1)
	{
		if (TF_DEBUG) printf("returned = \t|%s|\n", line);
		dprintf(outfd, "%s\n", line);
		free(line);
		line = NULL;
	}
	if (TF_DEBUG) printf("last = \t\t|%s|\n", line);
	if (line)
	{
		dprintf(outfd, "%s", line);
		free(line);
	}
	if (returned != 0) printf("ERROR: Did not return 0 at the end\n");
	returned = get_next_line(fd, &line);
	if (returned != 0) printf("repeated calls failing\n");
	close(outfd);
	close(fd);
	if (TF_DEBUG) printf("=================================================\n");
}

int	main(int argc, char **argv)
{
	char	*fake_line;

	if (argc != 2)
	{
		if (argc == 3)
		{
			if (get_next_line(42, &fake_line)  == -1)
				printf("done testing fake fd\n");
			else
				printf("ERROR: did not pass fake fd test\n");
		}
		else
			printf("incorrect arguments to testing program=====\n");
		return (1);
	}
	test(argv[1]);
	return (0);
}*/
/*
#include "ft_ansi.h"

void test_basic(void)
{
	size_t	line_count;
	char	*line;
	int	fd;

	line_count = 0;
	line = NULL;
	printf("Opening file... ");
	fd = open("test_basic_dino.txt", O_RDONLY);
	if (fd < 0)
	{
		printf(ANSI_F_RED "Error opening %s.\n" ANSI_RESET, "test_basic_dino.txt");
		return ;
	}
	printf("Done.\n");
	printf(ANSI_F_YELLOW "Reading Lines...\n" ANSI_RESET);
	while (get_next_line(fd, &line))
	{
		line_count++;
		printf(ANSI_F_CYAN "%zu" ANSI_RESET "\t|%s" ANSI_F_CYAN "$\n" ANSI_RESET, line_count, line);
		free(line);
	}
	if (line_count != 12)
		printf(ANSI_F_RED "ERROR: test_basic(...) failed.\n" ANSI_RESET);
	else
		printf(ANSI_F_GREEN "Done.\n" ANSI_RESET);
	printf(ANSI_F_YELLOW "[ Lines Expected: 12, Lines Read: %zu ]\n" ANSI_RESET, line_count);
	fd = close(fd);
	if (fd < 0)
	{
		printf(ANSI_F_BRED "Fatal Error: Could not close open file.\n" ANSI_RESET);
		exit(EXIT_FAILURE);
	}
}

void	test_poems(void)
{
	size_t	line_count;
	char	*line;
	int	fd_i;
	int	fd_a;
	int	fd_b;

	line = NULL;
	line_count = 0;
	fd_i = open("timmy_test_interleave.txt", O_RDONLY);
	fd_a = open("timmy_test_a.txt", O_RDONLY);
	fd_b = open("timmy_test_b.txt", O_RDONLY);
	if (fd_i < 0 || fd_a < 0 || fd_b < 0)
	{
		printf(ANSI_F_RED "Error opening files.\n" ANSI_RESET);
		return ;
	}
	printf(ANSI_F_YELLOW "Starting interleaved file read test...\n\n" ANSI_RESET);
	line_count = 0;
	while (line_count < 4)
	{
		line_count++;
		get_next_line(fd_i, &line);
		printf(ANSI_F_CYAN "%zu" ANSI_RESET "\t|%s" ANSI_F_CYAN "$\n" ANSI_RESET, line_count, line);
		free(line);
	}
	while (get_next_line(fd_a, &line))
	{
		line_count++;
		printf(ANSI_F_CYAN "%zu" ANSI_RESET "\t|%s" ANSI_F_CYAN "$\n" ANSI_RESET, line_count, line);
		free(line);
	}
	line_count++;
	get_next_line(fd_i, &line);
	printf(ANSI_F_CYAN "%zu" ANSI_RESET "\t|%s" ANSI_F_CYAN "$\n" ANSI_RESET, line_count, line);
	free(line);
	while (get_next_line(fd_b, &line))
	{
		line_count++;
		printf(ANSI_F_CYAN "%zu" ANSI_RESET "\t|%s" ANSI_F_CYAN "$\n" ANSI_RESET, line_count, line);
		free(line);
	}
	while (get_next_line(fd_i, &line))
	{
		line_count++;
		printf(ANSI_F_CYAN "%zu" ANSI_RESET "\t|%s" ANSI_F_CYAN "$\n" ANSI_RESET, line_count, line);
		free(line);
	}
	if (line_count != 45)
		printf(ANSI_F_RED "\nERROR: Interleaved files test failed! [ test_poems(...); ]\n" ANSI_RESET);
	else
		printf(ANSI_F_GREEN "\nDone.\n" ANSI_RESET);
	printf(ANSI_F_YELLOW "[ Lines Expected: 45, Lines Read: %zu ]\n" ANSI_RESET, line_count);
	fd_i = close(fd_i);
	fd_a = close(fd_a);
	fd_b = close(fd_b);
	if (fd_i < 0 || fd_a < 0 || fd_b < 0)
	{
		printf(ANSI_F_BRED "Fatal Error: Could not close open files!\n" ANSI_RESET);
		exit(EXIT_FAILURE);
	}
}

void	test_null_cases(void)
{
	char	*line;
	int		temp_fd;
	size_t	line_count;

	line = NULL;
	line_count = 0;
	temp_fd = open("test_null_cases.txt", O_RDONLY);
	printf("Testing failure cases...\n");
	printf("Passing NULL pointer to line parameter of get_next_line(...)\n");
	get_next_line(temp_fd, NULL);
	printf("Passing invalid file descriptor (fd = -1)...\n");
	get_next_line(-1, &line);
	printf("Passing invalid file descriptor and line pointer...\n");
	printf(ANSI_F_GREEN "Done.\n" ANSI_RESET "As a prize here is some text:\n\n");
	if (temp_fd < 0)
	{
		printf(ANSI_F_RED "Nevermind. The file couln't be opened so you get nothing :C\n" ANSI_RESET);
		return ;
	}
	while (get_next_line(temp_fd, &line))
	{
		line_count++;
		printf(ANSI_F_CYAN "%zu" ANSI_RESET "\t|%s" ANSI_F_CYAN "$\n" ANSI_RESET, line_count, line);
		free(line);
	}
	if (line_count == 16)
		printf("\nDid you enjoy your prize? Yes? Okay let's move on.\n");
	else
		printf(ANSI_F_RED "Hey! Your prize isn't working properly! What's going on?\n" ANSI_RESET);
	printf(ANSI_F_YELLOW "[ Prize lines read: %zu, Prize lines expected: 16 ]\n" ANSI_RESET, line_count);
	temp_fd = close(temp_fd);
	if (temp_fd < 0)
	{
		printf("Fatal Error: Could not close open file!\n");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	printf(ANSI_F_BCYAN "[ Testing get_next_line(...): ]\n");
	printf("[ Current Buffer Size: %.4d   ]\n\n" ANSI_RESET, BUFF_SIZE);
	test_basic();
	test_poems();
	test_null_cases();
	printf(ANSI_F_BCYAN "[ Test complete. ]\n" ANSI_RESET);
	return (0);
}*/
