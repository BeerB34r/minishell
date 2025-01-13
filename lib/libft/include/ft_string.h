#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t dsize);
char	*ft_stpcpy(char *dst, const char *src);
char	*ft_stpncpy(char *dst, const char *src, size_t dsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_strcat(char *dst, const char *src);
char	*ft_strncat(char *dst, const char *src, size_t ssize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchrnul(const char *s, int c);
char	*ft_strrchrnul(const char *s, int c);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strcasecmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strncasecmp(const char *s1, const char *s2, size_t n);

size_t	ft_strspn(const char *s, const char *accept);
size_t	ft_strcspn(const char *s, const char *reject);
size_t	ft_strrspn(const char *s, const char *accept);
size_t	ft_strrcspn(const char *s, const char *reject);

char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);

char	*ft_strfry(char *string);

char	*ft_strerror(int errno);

size_t	ft_strlen(const char *s);

char	*ft_strpbrk(const char *s, const char *accept);
char	*ft_strcpbrk(const char *s, const char *reject);
char	*ft_strrpbrk(const char *s, const char *accept);
char	*ft_strrcpbrk(const char *s, const char *reject);
char	*ft_strpbrknul(const char *s, const char *accept);
char	*ft_strcpbrknul(const char *s, const char *reject);
char	*ft_strrpbrknul(const char *s, const char *accept);
char	*ft_strrcpbrknul(const char *s, const char *reject);

char	*ft_strsep(char **stringp, const char *delim);

char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrstr(const char *haystack, const char *needle);
char	*ft_strcasestr(const char *haystack, const char *needle);
char	*ft_strrcasestr(const char *haystack, const char *needle);

char	*ft_strtok(char *str, const char *delim);
char	*ft_strtok_r(char *str, const char *delim, char **saveptr);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memccpyr(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memmem(const void *haystack, size_t haystacklen,
			const void *needle, size_t needlelen);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memchrr(const void *s, int c, size_t n);
void	*ft_memfrob(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);

#endif
