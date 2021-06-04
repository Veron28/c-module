from distutils.core import setup, Extension
# from jaraco.develop import msvc
# msvc.patch_msvc9compiler_module()




module1 = Extension(
	'my_rand', # название модуля внутри Python
	 sources = ['pymodule.c'] # Исходные файлы модуля
)

setup(
	name = 'my_rand',              # название модуля (my_plus.__name__)
	version = '1.1',               # версия модуля
	description = 'Simple module', # описание модуля
	ext_modules= [module1]         # объекты типа Extension (мы объявили его выше)
)