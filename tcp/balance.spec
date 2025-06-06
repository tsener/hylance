
# spec file by Steudten Engineering, <rpmbuild at steudten dot com>
%define  __prefix /usr

Summary: TCP load-balancing proxy server
Name: balance
Version: 3.34
Release: 1
Group: Networking/Daemons
Source: http://www.inlab.de/%{name}-%{version}.tar.gz
License: GPL 
BuildRoot: %{_tmppath}/%{name}-%{version}-buildroot
BuildRequires: ghostscript > 7, rpm-build > 4.1

Prefix: %{__prefix}

%description
Balance is a simple but powerful generic tcp proxy with round robin
load balancing and failover mechanisms. Its behaviour can be controlled
at runtime using a simple command line syntax. 

This package is relocatable. Use 'rpm (i|U)vh --prefix=<newpath> balance.rpm'
to install the binary, the manpage and the docs under <newpath>. Or use
'rpm (i|U)vh --relocate=/usr/sbin=<newpath> balance.rpm' to install only the
binary in a different location.
NOTICE: The /var/run/balance/ must be fix at this time.

%prep
%setup 
%build

make CFLAGS="${CFLAGS:-$RPM_OPT_FLAGS -Wall}"
	
%install
[ "${RPM_BUILD_ROOT}" != "/" ] && rm -rf ${RPM_BUILD_ROOT}
mkdir -p    $RPM_BUILD_ROOT/var/run/balance
chmod 1777  $RPM_BUILD_ROOT/var/run/balance
install -D -m 755 balance   $RPM_BUILD_ROOT%{__prefix}/sbin/balance
install -D -m 644 balance.1 $RPM_BUILD_ROOT%{_mandir}/man1/balance.1

%clean
[ "${RPM_BUILD_ROOT}" != "/" ] && rm -rf ${RPM_BUILD_ROOT}

%files
%defattr(-,root,root)
%doc README COPYING balance.pdf
%{__prefix}/sbin/balance
%{_mandir}/man1/balance.1*
%attr(1777,root,root) %dir /var/run/balance

%changelog
* Wed Mar 29 2006 Steudten Engineering <rpmbuild at steudten dot com> 3.34-1
- rebuilt

* Wed Oct 26 2005 Steudten Engineering <rpmbuild at steudten dot com> 3.31-1
- remove strip binary and gzip manpage..
- add -D to install
- rebuilt

* Wed Sep 21 2005 Steudten Engineering <rpmbuild at steudten dot com> 3.26-1
- rebuilt

* Sun Jul 10 2005 Thomas Steudten <thomas at steudten dot com> 3.24-1
- rebuilt

* Sun Mar 13 2005 Thomas Steudten <thomas at steudten dot com> 3.22-1
- add build requirement for ghostscript
- add balance.pdf for docs
- rebuilt

* Sat Dec 04 2004 Thomas Steudten <thomas at steudten dot com> 3.19-1
- rebuilt

* Fri Jun 18 2004 Thomas Steudten <thomas at steudten dot com> 3.15-1
- rebuilt

* Thu May 20 2004 Thomas Steudten <thomas at steudten dot com> 3.13-1
- rebuilt

* Sun Oct 5 2003 Thomas Steudten <thomas at steudten dot com> 3.11-1
- rebuilt
- fix some values in this file.
- add relocation information.

* Wed Sep 24 2003 Thomas Steudten <thomas at steudten dot com> 3.10a-2 
- fix wrong version in balance.1 file.
- add new specfile to source.

* Mon Sep  22 2003 Thomas Steudten <thomas at steudten dot com> 3.10-2 
- rebuilt
- fix/expand specfile
