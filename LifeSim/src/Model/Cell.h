#pragma once
#include <string>

namespace Life {

	class Cell
	{
	public:
		Cell() : m_Alive(false) {}
		~Cell() {}

		inline bool isAlive() const { return m_Alive; }
		inline void setAlive(bool alive) { m_Alive = alive; }

		std::string ToString() { return "Cell!, It's dead right now...\n"; }
	private:
		bool m_Alive;
	};

}