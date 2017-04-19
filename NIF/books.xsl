<?xml version="1.0"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
	  <html>
		<head>
			<link rel="stylesheet" type="text/css" href="books.css"></link>
		</head>
	<body>
	<xsl:for-each select="catalog/book">
		<div class='header'>
			Author: <xsl:value-of select="author"/>
		</div>
		<br></br>
		Title: <xsl:value-of select="title"/>
		<br></br>
		Genre: <xsl:value-of select="genre"/> 
		<br></br>
		<div class='price'>
			Price: <xsl:value-of select="price"/> 
		</div>
	   <br></br>
	</xsl:for-each>
	</body>
	  </html>
	</xsl:template>
</xsl:stylesheet>