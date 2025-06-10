# Maintainer: SpaciousCoder78 <aryankmmiv@outlook.com>
pkgname=QuickOverflow
pkgver=3.0.0
pkgrel=1
pkgdesc="A CLI Tool to auto-detect code errors and open solutions"
arch=('x86_64')
url="https://github.com/SpaciousCoder78/QuickOverflow"
license=('GPL3')
depends=('python' 'python-pipenv' 'python-pip' 'gcc' 'pyinstaller')
makedepends=('python-pipenv' 'python-pip' 'gcc' 'pyinstaller')
source=("https://github.com/SpaciousCoder78/QuickOverflow/releases/download/v3.0.0/QuickOverflow3.0.0.tar.gz")
md5sums=('SKIP')

build() {
	cd "$srcdir/QuickOverflow$pkgver"
	# Install Python dependencies using pipenv, if Pipfile exists
	if [[ -f Pipfile ]]; then
		pipenv install --python python3
		pipenv run pip install -r requirements.txt
		pipenv install pyinstaller
	fi

	# Build the C binary
	gcc main.c -o QuickOverflow

	# Make search.py executable and build the PyInstaller binary
	chmod +x search.py
	pipenv run pyinstaller --onefile --name search search.py

}

package() {
	cd "$srcdir/QuickOverflow$pkgver"
	# Install C binary
	install -Dm755 QuickOverflow "$pkgdir/usr/bin/QuickOverflow"
	# Install Python binary built by PyInstaller
	install -Dm755 dist/search "$pkgdir/usr/bin/search"
}