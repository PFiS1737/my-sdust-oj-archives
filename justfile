set shell := ["fish", "-c"]

default:
    @just config debug build then run

then:
    @echo

config mode:
    @xmake config -m {{mode}}

build:
    @xmake build

[no-exit-message]
run:
    @xmake run

checkout id='':
    @./scripts/checkout {{id}}

[no-exit-message]
judge:
    @./scripts/judge

new *args:
    @./scripts/new {{args}}

archive:
    @./scripts/archive

clean:
    @xmake clean

distclean:
    @rm -rf ./build
    @rm -rf ./.xmake
    @rm -rf ./.cache
