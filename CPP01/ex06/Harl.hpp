#pragma once

#include <string>

class Harl {
	private:
		void	debug(void);
		void	info(void );
		void	warning(void);
		void	error(void);

		typedef void (Harl::*func)();
		const func			funcHandle[4] = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
		};
		const std::string	levelHandle[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
		};

	public:
		static int		filterLevel;
		void			complain(const std::string& level);
		void			setFilterLevel(int i);
		std::string		getFilterLevel(int i) const;
};
