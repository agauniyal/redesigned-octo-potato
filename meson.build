project('redesigned-octo-potato', 'cpp', version : '0.1.0',
		default_options : ['cpp_std=c++11'])

inc = include_directories('include')

thread_dep = dependency('threads')
rang_sp = subproject('rang')
rang_dep = rang_sp.get_variable('rang_dep')

subdir('src')
