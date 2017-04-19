require 'socket'
a = TCPServer.new('', 3333) # '' means to bind to "all interfaces", same as nil or '0.0.0.0'
list = []
i = 0
loop {
  connection = a.accept
  if connection 
	i = i + 1
  end
  list.push(i.to_s + '.' + '  ' + connection.recv(1024))
  connection.write list.join("\n")
  connection.close
}