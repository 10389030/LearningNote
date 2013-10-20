""" research the usage of Python anotation """

def logger(fn):
    """ declare a function which will be used as anotation 

        :param fn: the function instance that use this anotation
    """

    print type(fn)

    def new(*args):    
        """ this function must be consitent with the caller """

        print "called with name:", str(*args)
        result = fn(*args)
        print "result is", result

        return result

    return new    # must return a callable function

@logger
def hi(args):
    print args
    print "calling function"
    return "name" 

hi("name")


""" implement a anotation with parameter """
def pl(msg):
    """ this is a wraper for anotation, in other world, this is a anotation
        factory

        :param msg: str, the anotation parameter
        :return a function which take function as parameter, which actually be
                the anotation function
    """

    def wraper(fn):
        def new(arg):
            print "msg:", msg
            print "before", fn.__name__
            result = fn(arg)
            print "after", fn.__name__
        return new
    
    return wraper

@pl("fuck you")  # just like call function (factory) and get a product, which
                 # is function wraper(fn) with a closured variable msg.
def fun(arg):
    pass

fun(1)
