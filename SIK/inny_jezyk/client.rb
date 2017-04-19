require 'socket'
a = TCPSocket.new('127.0.0.1', 3333) # could replace 127.0.0.1 with your "real" IP if desired.
a.write Time.now.inspect
puts "Zarejestrowane wejscia: \n" + a.recv(1024)
sleep 2
a.close