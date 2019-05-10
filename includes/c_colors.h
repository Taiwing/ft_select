/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_colors.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 09:28:29 by yforeau           #+#    #+#             */
/*   Updated: 2019/05/10 11:27:46 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_COLORS_H
# define C_COLORS_H

# define C_RESET		"\x1b[0m"

# define C_FG_BLACK		"\x1b[30m"
# define C_FG_RED		"\x1b[31m"
# define C_FG_GREEN		"\x1b[32m"
# define C_FG_YELLOW	"\x1b[33m"
# define C_FG_BLUE		"\x1b[34m"
# define C_FG_MAGENTA	"\x1b[35m"
# define C_FG_CYAN		"\x1b[36m"
# define C_FG_WHITE		"\x1b[37m"
# define C_FG_DEFAULT	"\x1b[39m"

# define C_BG_BLACK		"\x1b[40m"
# define C_BG_RED		"\x1b[41m"
# define C_BG_GREEN		"\x1b[42m"
# define C_BG_YELLOW	"\x1b[43m"
# define C_BG_BLUE		"\x1b[44m"
# define C_BG_MAGENTA	"\x1b[45m"
# define C_BG_CYAN		"\x1b[46m"
# define C_BG_WHITE		"\x1b[47m"
# define C_BG_DEFAULT	"\x1b[49m"

# define C_REVERSE		"\x1b[7m"
# define C_NO_REVERSE	"\x1b[27m"

# define C_UNDERLINE	"\033[4m"
# define C_NO_UNDERLINE	"\033[24m"

# define C_BOLD			"\033[1m"
# define C_NO_BOLD		"\033[22m"

#endif
