#ifndef RPN_HPP
# define RPN_HPP
# include <stack>

class RPN
{
	public:
		RPN();
		RPN(const RPN &src);
		RPN& operator=(const RPN &src);
		~RPN();

		void	push_back(double d);
		void	pop_back(void);
		double	getTop(void);

		int		operation(char c);

	private:
		std::stack<double> _stack;
};

std::ostream& 	operator<<(std::ostream&out, const RPN &toPrint);

#endif
