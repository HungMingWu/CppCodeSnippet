#ifndef _Scoped_Thread_H_
#define _Scoped_Thread_H_
#include <thread>
class scoped_thread {
	std::thread t;
public:
	explicit scoped_thread(std::thread &&t_) : t(std::move(t_)){
		if (!t.joinable())
			throw std::logic_error("No thread");
	}
	~scoped_thread() {
		t.join();
	}
	scoped_thread(scoped_thread &)= delete;
	scoped_thread& operator=(const scoped_thread&) = delete;
};
#endif
