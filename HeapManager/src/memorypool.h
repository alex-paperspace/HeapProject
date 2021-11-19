#pragma once

namespace pool {

	union Chunk {
		char* next;
		char buffer[8];
	};

	class Pool {

	};
	
}

