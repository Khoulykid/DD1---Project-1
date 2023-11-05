#pragma once
#ifndef FUNCTION_7_H
#define FUNCTION_7_H
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;

vector<vector<int>> fourVariables(vector<vector<int>> &kmap, vector<string> minmized, int i)
{
	if (minmized[i] == "a'b'c'd'")
	{
		kmap = {
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'b'c'd")
	{
		kmap = {
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'b'cd")
	{
		kmap = {
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'b'cd'")
	{
		kmap = {
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'bc'd'")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'bc'd")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'bcd")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'bcd'")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "abc'd'")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "abc'd")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "abcd")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "abcd'")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "ab'c'd'")
	{
	kmap = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 1, 0, 0, 0 }
	};
	}
	else if (minmized[i] == "ab'c'd")
	{
	kmap = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 1, 0, 0 }
	};
	}
	else if (minmized[i] == "ab'cd")
	{
	kmap = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 1, 0 }
	};
	}
	else if (minmized[i] == "ab'cd'")
	{
	kmap = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 1 }
	};
	}
	
	return kmap;

};

vector<vector<int> > threeVariables(vector<vector<int>> &kmap, vector<string> minmized, int i)
	{
		if (minmized[i] == "a'b'c'")
		{
			kmap = {
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "a'b'c")
		{
			kmap = {
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "a'b'd'")
		{
			kmap = {
			{ 1, 0, 0, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "a'b'd")
		{
			kmap = {
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "a'bc'")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "a'bc")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "a'bd'")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 1, 0, 0, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "a'bd")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "abc'")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "abc")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "abd'")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 0, 0, 1 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "abd")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "ab'c'")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 1, 0, 0 }
			};
		}
		else if (minmized[i] == "ab'c")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 1 }
			};
		}
		else if (minmized[i] == "ab'd'")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 0, 0, 1 }
			};
		}
		else if (minmized[i] == "ab'd")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 }
			};
		}
		else if (minmized[i] == "a'c'd'")
		{
			kmap = {
			{ 1, 0, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "ac'd'")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 1, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "b'c'd'")
		{
			kmap = {
			{ 1, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "bc'd'")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "a'c'd")
		{
			kmap = {
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "ac'd")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 }
			};
		}
		else if (minmized[i] == "b'c'd")
		{
			kmap = {
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 }
			};
		}
		else if (minmized[i] == "bc'd")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "a'cd")
		{
			kmap = {
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "acd")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 }
			};
		}
		else if (minmized[i] == "b'cd")
		{
			kmap = {
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 0 }
			};
		}
		else if (minmized[i] == "bcd")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "a'cd'")
		{
			kmap = {
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
			};
		}
		else if (minmized[i] == "acd'")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 1 }
			};
		}
		else if (minmized[i] == "b'cd'")
		{
			kmap = {
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 1 }
			};
		}
		else if (minmized[i] == "bcd'")
		{
			kmap = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 0 }
			};
		}

	
	return kmap;
}
vector<vector<int>> twoVariables(vector<vector<int>> &kmap, vector<string> minmized, int i)
{

	if (minmized[i] == "a'b'")
	{
		kmap = 
		{
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "ab'")
	{
		kmap = 
		{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 }
		};
	}
	else if (minmized[i] == "a'b")
	{
		kmap = 
		{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "ab")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "c'd'")
	{
		kmap = {
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "c'd")
	{
		kmap = {
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 }
		};
	}
	else if (minmized[i] == "cd")
	{
		kmap = {
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 }
		};
	}
	else if (minmized[i] == "cd'")
	{
		kmap = {
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 1 }
		};
	}
	else if (minmized[i] == "a'c'")
	{
		kmap = {
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "ac'")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 }
		};
	}
	else if (minmized[i] == "a'd'")
	{
		kmap = {
		{ 1, 0, 0, 1 },
		{ 1, 0, 0, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "ad'")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 0, 0, 1 },
		{ 1, 0, 0, 1 }
		};
	}
	else if (minmized[i] == "a'd")
	{
		kmap = {
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	}
	else if (minmized[i] == "ad")
	{
	kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 }
	};
	}
	else if (minmized[i] == "a'c")
	{
	kmap = {
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	}
	else if (minmized[i] == "ac")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 1 }
	};
	}
	else if (minmized[i] == "b'c'")
	{
	kmap = {
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 0, 0 }
	};
	}
	else if (minmized[i] == "b'd")
	{
	kmap = {
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 }
	};
	}
	else if (minmized[i] == "b'c")
	{
	kmap = {
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 1 }
	};
	}
	else if (minmized[i] == "b'd'")
	{
	kmap = {
		{ 1, 0, 0, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 0, 0, 1 }
	};
	}
	else if (minmized[i] == "bd'")
	{
	kmap = {
		{ 0, 0, 0, 0 },
		{ 1, 0, 0, 1 },
		{ 1, 0, 0, 1 },
		{ 0, 0, 0, 0 }
	};
	}
	else if (minmized[i] == "bd")
	{
	kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	};
	}
	else if (minmized[i] == "bc")
	{
	kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 0 }
	};
	}
	else if (minmized[i] == "bc'")
	{
	kmap = 
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	}

	return kmap;
}
vector<vector<int>> oneVariables(vector<vector<int>> &kmap, vector<string> minmized, int i)
{

	if (minmized[i] == "a'")
	{
		kmap = {
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "b'")
	{
		kmap = {
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 }
		};
	}
	else if (minmized[i] == "b")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 }
		};
	}
	else if (minmized[i] == "c'")
	{
		kmap = {
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 }
		};
	}
	else if (minmized[i] == "d")
	{
		kmap = {
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 }
		};
	}
	else if (minmized[i] == "d'")
	{
		kmap = {
		{ 1, 0, 0, 1 },
		{ 1, 0, 0, 1 },
		{ 1, 0, 0, 1 },
		{ 1, 0, 0, 1 }
		};
	}
	else if (minmized[i] == "c")
	{
		kmap = {
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 1 }
		};
	}

	return kmap;
}
// ---------------------------------------------------------------------------------------------------------------------------------
// 3 variables function
vector<vector<int> > threeforthree(vector<vector<int>> &kmap, vector<string> minmized, int i)
{
	if (minmized[i] == "a'b'c'")
	{
		kmap = {
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'b'c")
	{
		kmap = {
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'bc")
	{
		kmap = {
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'bc'")
	{
		kmap = {
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "ab'c'")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 1, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "ab'c")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 }
		};
	}
	else if (minmized[i] == "abc")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 0 }
		};
	}
	else if (minmized[i] == "abc'")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 1 }
		};
	}
	return kmap;
}
vector<vector<int>> threefortwo(vector<vector<int>> &kmap, vector<string> minmized, int i)
{
	if (minmized[i] == "a'b'")
	{
		kmap = {
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'c")
	{
		kmap = {
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'b")
	{
		kmap = {
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a'c'")
	{
		kmap = {
		{ 1, 0, 0, 1 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "bc'")
	{
		kmap = {
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 1 }
		};
	}
	else if (minmized[i] == "ac'")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 1, 0, 0, 1 }
		};
	}
	else if (minmized[i] == "ab'")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 1, 1, 0, 0 }
		};
	}
	else if (minmized[i] == "ac")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 }
		};
	}
	else if (minmized[i] == "ab")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 1 }
		};
	}
	else if (minmized[i] == "b'c'")
	{
		kmap = {
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "b'c")
	{
		kmap = {
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 }
		};
	}
	else if (minmized[i] == "bc")
	{
		kmap = {
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 }
		};
	}
	return kmap;
}
vector<vector<int>> threeforone(vector<vector<int>> &kmap, vector<string> minmized, int i)
{
	if (minmized[i] == "a'")
	{
		kmap = {
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 }
		};
	}
	else if (minmized[i] == "a")
	{
		kmap = {
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 }
		};
	}
	else if (minmized[i] == "b'")
	{
		kmap = {
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 }
		};
	}
	else if (minmized[i] == "b")
	{
		kmap = {
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 1 }
		};
	}
	else if (minmized[i] == "c'")
	{
		kmap = {
		{ 1, 0, 0, 1 },
		{ 1, 0, 0, 1 }
		};
	}
	else if (minmized[i] == "c")
	{
		kmap = {
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 }
		};
	}

	return kmap;
}
// ---------------------------------------------------------------------------------------------------------------------------------
// two variable functions


vector<vector<int> > twofortwo(vector<vector<int>> &kmap, vector<string> minmized, int i)
{
	if (minmized[i] == "a'b'")
	{
		kmap = {
		{ 1, 0 },
		{ 0, 0 }
		};
	}
	else if (minmized[i] == "a'b")
	{
		kmap = {
		{ 0, 1 },
		{ 0, 0 }
		};
	}
	else if (minmized[i] == "ab'")
	{
		kmap = {
		{ 0, 0 },
		{ 1, 0 }
		};
	}
	else if (minmized[i] == "ab")
	{
		kmap = {
		{ 0, 0 },
		{ 0, 1 }
		};
	}
	return kmap;
}

vector<vector<int> > twoforone(vector<vector<int>> &kmap, vector<string> minmized, int i)
{
	if (minmized[i] == "a'")
	{
		kmap = {
		{ 1, 1 },
		{ 0, 0 }
		};
	}
	else if (minmized[i] == "a")
	{
		kmap = {
		{ 0, 0 },
		{ 1, 1 }
		};
	}
	else if (minmized[i] == "b'")
	{
		kmap = {
		{ 1, 0 },
		{ 1, 0 }
		};
	}
	else if (minmized[i] == "b")
	{
		kmap = {
		{ 0, 1 },
		{ 0, 1 }
		};
	}
	return kmap;
}
// printing functions 
void print(vector<vector<int>> kmap, vector<string> min)
{
	
		for (int i = 0; i < kmap.size(); i++)
		{
			
				for (int j = 0; j < kmap[i].size(); j++)
				{
					cout << kmap[i][j];

					if (j < kmap[i].size() - 1) {
						cout << " | "; // vertical bar between columns
					}
				}

			cout << endl;

			if (i < kmap.size() - 1) {
				for (int j = 0; j < kmap[i].size(); j++) {
					cout << "-"; // dashes for each column
					if (j < kmap[i].size() - 1) {
						cout << " | "; // vertical bar between columns
					}
				}
				cout << endl;
			}
		}
		cout << endl;
	
	
};
void print2(vector<int> kmap, vector<string> min)
{

	cout << kmap[0] << " | " << kmap[1] << endl;
	cout << endl;

};
void f7(vector<string> minmized, string variables)
{
	int n = variables.length();
	string masking = "abcd";
	vector<string> temp;
	vector<int> countalpha(minmized.size(), 0);
	
	for (int i = 0; i < minmized.size(); i++) //Masking
	{
		string tempo("");
		for (int j = 0; j < minmized[i].length(); j++)
		{
			if (minmized[i][j] == '\'')
				tempo += minmized[i][j];
			else
				for (int k = 0; k < variables.length(); k++)
			
					if (minmized[i][j] == variables[k])
					{
						tempo += masking[k];
						countalpha[i] ++;
					}
		}
		temp.push_back(tempo);

	}
	if (variables.length() == 4)
	{
		vector<vector<int>> kmap =
		{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
		};

		for (int i = 0; i < countalpha.size(); i++)
		{
			if (countalpha[i] == 4)
			{
				fourVariables(kmap, temp, i);

			}
			else if (countalpha[i] == 3)
			{
				threeVariables(kmap, temp, i);

			}
			else if (countalpha[i] == 2)
			{
				twoVariables(kmap, temp, i);

			}
			else if (countalpha[i] == 1)
			{
				oneVariables(kmap, temp, i);

			}
			
			cout << "Cover:" << minmized[i] << endl;
			print(kmap, minmized);

		}


	}
	else if (variables.length() == 3)
	{
		vector<vector<int>> kmap = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		};
		for (int i = 0; i < countalpha.size(); i++)
		{
			if (countalpha[i]==3)
			{
				threeforthree(kmap, temp, i);
			}
			else if (countalpha[i] == 2)
			{
				threefortwo(kmap, temp, i);
			}
			else
				threeforone(kmap, temp, i);

			cout << "Cover:" << minmized[i] << endl;

			print(kmap, minmized);
		}

	}
	else if (variables.length() == 2)
	{
		vector<vector<int>> kmap = {
		{0, 0},
		{0, 0},

		};
		for (int i = 0; i < countalpha.size(); i++)
		{

			if (countalpha[i] == 2)
			{
				twofortwo(kmap, temp, i);
			}
			else
			{
				twoforone(kmap, temp, i);
			}
			cout << "Cover:" << minmized[i] << endl;

			print(kmap, minmized);

		}


	}
	else if (variables.length() == 1)
	{
		vector<int> kmap = 
		{
		{0, 0},
		};
		for (int i = 0; i < countalpha.size(); i++)
		{
			if (temp[i] == "a")
			{
				kmap = 
				{
					{0, 1}
				};
			}
			else if (temp[i] == "a'")
			{
				kmap = 
				{
					{1, 0}
				};
			}
			cout << "Cover:" << minmized[i] << endl;

			print2(kmap, minmized);
		}


	}
};

#endif
