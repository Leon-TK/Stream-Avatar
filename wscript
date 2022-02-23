APPNAME = 'StreamAvatar'
VERSION = '0.0.0.1'

top = '.'
out = 'WAF_BUILD'

def options(ctx):
        ctx.load("compiler_cxx")
        
        ctx.load("poco")
        ctx.load("rt")
        ctx.load("sfml")
        ctx.load("openssl")

        standart = ctx.add_option_group('Standart')
        standart.add_option('-p', '--platform', action = 'store', dest = 'PLATFORM', default = "win64",
		help = 'platform to use')
        standart.add_option('-c', '--configuration', action = 'store', dest = 'CONF', default = "debug",
		help = 'configuration to use')
        standart.add_option('-t', '--type', action = 'store', dest = 'TYPE', default = "game",
		help = 'type to use')
        standart.add_option('-pt', '--plugintype', action = 'store', dest = 'PTYPE', default = None,
		help = 'plugin type to use')

def configure(ctx):
        ctx.load("compiler_cxx")

        ctx.env.PLATFORM = ctx.otions.platform
        ctx.env.CONF = ctx.options.conf
        ctx.env.TYPE = ctx.options.type
        ctx.env.PTYPE = ctx.options.ptype
        #debug - very slow, easy to debug
        #release - very fast, hard to debug
        #profile - only profile enabled, debug is off
        #developer - between debug and release
        print('→ configuring the project in ' + ctx.path.abspath())

def build_game(ctx):
        pass
def build_editor(ctx):
        pass
def build_engine(ctx):
        pass

def build(ctx):
        ctx.to_log("Use other build commands")

        #do compile to variants folders using different configuration sets

        types = "engine editor game program plugin".split()
        ptypes = types.remove("plugin")
        configurations = "debug developer profile release".split()
        platforms = "win32 win64 linux android ios".spli()
        exportLibIncludeFolderName = "include"

        libsNodes = ctx.path.find_node("thirdparty\\libs").children
        pluginsNodes = ctx.path.find_node("plugins").children

        gameNode = ctx.path.find_node("game") #TODO use ant_glob to find *project node
        gameMetaRaw = gameNode.path.find_node("meta.json").read()

        editorNode = ctx.path.find_node("editor")
        editorMetaRaw = editorNode.path.find_node("meta.json").read()

        engineNode = ctx.path.find_node("engine")

        #need to copy dependencies dlls to each target
        
        #copy all headers in "include" folder of targets

        #thirdparty:
                #rt - lib
                #Poco - lib
                #openssl - lib
                #sfml - lib

        #engine - dll, depens: rt, poco, openssl, sfml
                #???core - dll, private
                #???sdk - dll, include folder

        #editor - exe, depens: engine(init link)
        #project - exe, depens: engine(init link)

        #engine build. Build engine dll with linked libs
        #editor build. Find engine headers, build editor, copy all engine dlls
        #game build. Find engine headers, find plugins headers, build game, copy all engine dlls and plugins dlls
        #plugins build. Find projecttype's(for now it's "game") headers, engine headers,