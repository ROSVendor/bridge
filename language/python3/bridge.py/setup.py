from distutils.core import setup, Extension

module1 = Extension('bridge',
                    sources = ['bundle.c', 'bundle_method.c', 'bridge_method.c', 'bridge.c'])

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])