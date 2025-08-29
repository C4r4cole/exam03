
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#  define BUF_SIZE 1024 //on definit le buffer

char  *ft_strchr(char *s, int c)
{
  int i = 0;
  if (!s)//securité
		return NULL;
  while (s[i] && s[i] != c) // on oublie pas s[i]
      i++;
  if (s[i]  == c)
    return (s+i);
  else
    return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t n) //faire cette fonction comme ca
{
  size_t i = 0;//on créer i 
  while (i < n)//on linsert
  {
    ((char *)dest)[i] = ((char *)src)[i];
    i++;
  }
  return dest;
}

size_t ft_strlen(char *s)//on change rien
{
  size_t ret = 0;
  while(*s)
    {
      s++;
      ret++;
    }
  return (ret);
}


int str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t size1 = 0;
	char *tmp;//on le fait plus tard le malloc apres les sécuités

	if (!s1 || !s2)//sécurité
		return 0;
	if (*s1)
		size1 = ft_strlen(*s1);//on met le strlen plus loin pour sassurer que cest ok
	tmp = malloc(size1 + size2 + 1);
	if (!tmp)
		return 0;
	if (*s1) //on ajoute cette condition
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';//on met '\0'
	free(*s1);
	*s1 = tmp;
	return 1;
}

int  str_append_str(char **s1, char *s2)
{
    return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void  *ft_memmove (void *dest, const void *src, size_t n)
{
	size_t i;// on change la place du i

	if (dest == src || n == 0) //dabord le = et n = 0
		return dest;
	if (dest > src)//ca faut juste l'apprendre 
	{
		while (n-- > 0)
			((char *)dest)[n] = ((char *)src)[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return dest;
}

char *get_next_line(int fd)
{
	static char b[BUF_SIZE + 1] = "";
	char *ret = NULL;
	char *tmp;//toujours plus tard
	int read_ret;//declare maintenant 

	while (1)//boucle infini
	{
		tmp = ft_strchr(b, '\n');
		if (tmp)
			break;
		if (*b)
		{
			if (!str_append_str(&ret, b))
				return NULL;
		}
		read_ret = read(fd, b, BUF_SIZE);
		if (read_ret <= 0)
		{
			if (read_ret == 0 && ret)
			{
				b[0] = '\0';
				return ret;
			}
			free(ret);
			return NULL;
		}
		b[read_ret] = '\0';
	}
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return NULL;
	}
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1); // déplacer le reste
	return ret;
}

int main(void)
{
	int fd;
	char *test;
	int i;

	i = 0;
	test = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (i != 2)
	{
		test = get_next_line(fd);
		printf("%s\n", test);
		free(test);
		i++;
	}
	close(fd);
	get_next_line(fd);
	return (0);
}
