/*
 * pgpry - PGP private key recovery
 * Copyright (C) 2010 Jonas Gehring
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * file: regexfilter.h
 * Buffer filtering with regular expressions
 */


#ifndef REGEXFILTER_H_
#define REGEXFILTER_H_


#include <vector>

#include "filter.h"

#include <tbb/tbb.h>
#include <tbb/pipeline.h>

class RegexFilter : public Filter, public tbb::filter
{
	public:
		RegexFilter();

		bool readExpressions(const std::string &file);
		void * operator()(void *input);

	protected:
		void run();
		//Memblock * operator()(Memblock *input) const;
		//void * operator()(void *input);

	private:
		std::vector<SysUtils::Regex> m_posrx;
		std::vector<SysUtils::Regex> m_negrx;
};


#endif
