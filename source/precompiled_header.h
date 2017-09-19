// QUICKFIX
#include <quickfix/Application.h>
#include <quickfix/MessageCracker.h>
#include <quickfix/ThreadedSocketAcceptor.h>
#include <quickfix/FileStore.h>
#include <quickfix/SocketInitiator.h>
#include <quickfix/SessionSettings.h>
#include <quickfix/Log.h>
#include <quickfix/Session.h>
#include <quickfix/Values.h>
#include <quickfix/fix42/ExecutionReport.h>
#include <quickfix/fix42/OrderCancelRequest.h>
// STD
#include <type_traits>
#include <functional>
#include <string>
#include <memory>
#include <exception>
#include <utility>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include <new>
#include <limits>
#include <stdexcept>
// STD THREADS
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
// STD C
#include <ctime>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cctype>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include <cstdlib>
// STD STL
#include <algorithm>
#include <vector>
#include <unordered_map>
// BOOST
#include <boost/optional.hpp>
#include <boost/any.hpp>
#include <boost/format.hpp>
// LINUX
#ifdef __linux__
#include <string.h>
#include <sched.h>
#include <pthread.h>
#include <syscall.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <linux/user.h>
#include <malloc.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/mman.h>
#endif
// WINDOWS
#ifdef _WIN32
#include <windows.h>
#include <malloc.h>
#endif