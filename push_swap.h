#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# define ABS(x) (x < 0) ? (-x) : (x)
# define MIN(x, y) (x < y) ? (x) : (y)
# define MAX(x, y) (x > y) ? (x) : (y)
# define UTIL 2147483647
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define RANGE 4294967295
# define SMART_FREE(x) {free(x); x = NULL;}
# define FAIL "KO\n"
# define SUCCESS "OK\n"
# define ERROR "Error\n"

typedef	struct	s_stack
{
	int			*a;
	int			*b;
	int			*all;
	int			a_start;
	int			a_end;
	int			b_start;
	int			b_end;
	int 		a_used;
	int 		b_used;
	int			size;
	int			counter;
	int			min;
	int			max;
}				t_stack;

void	new_stack(t_stack **stack, int size);
void	free_stack(t_stack **stack);
int		validate(char *str, t_stack **stack);
int		is_sorted(int ar[], int size, int start, int used);
int		is_sorted_rev(int ar[], int size, int start, int used);
int		ft_atoi(char *str);
int		ft_getnum(char *str, int *value);
int		ft_nbrsize(long n);
int		ft_isdigit(int c);
void	ft_putchar(int c);
void	ft_putstr(char const *s);
char	*ft_itoa_base(int n, int base);
char	**ft_strsplit(char const *s, char c);
void	ft_strdelall(char **str);
void	*ft_memset(void *ptr, int value, size_t num);
int		get_next(const int size, const int n);
int		get_mid(const int start, const int size, const int used);
int		get_max(const int arr[], const int size, const int start, int used);
int 	get_min(const int arr[], const int size, const int start, int used);
int		get_after(const int val, const int next, t_stack *stack);
void	sort_arr(t_stack *stack);
void	small_sort_arr(t_stack *stack);
void	push_b(t_stack *stack);
void	push_a(t_stack *stack);
void	roll_a(t_stack *stack);
void	roll_b(t_stack *stack);  
void	ft_print_both(t_stack *stack);
void	a_move_up(t_stack *stack);
void	a_move_down(t_stack *stack);
void	b_move_up(t_stack *stack);
void	b_move_down(t_stack *stack);
void	sa_swap (t_stack *stack);
void	sb_swap (t_stack *stack);
void	ss_swap(t_stack *stack);
void	pa_swap(t_stack *stack);
void	pb_swap(t_stack *stack);
void	ra_swap(t_stack *stack);
void	rb_swap(t_stack *stack);
void	rr_swap(t_stack *stack);
void	rra_swap(t_stack *stack);
void	rrb_swap(t_stack *stack);
void	rrr_swap(t_stack *stack);

#endif