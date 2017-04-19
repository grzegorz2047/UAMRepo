<?xml version="1.0"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
	  <html>
		<head>
			<link rel="stylesheet" type="text/css" href="osoby.css"></link>
		</head>
	  <body>
		<xsl:for-each select="people/person">
			   Name: <div class='header'><xsl:value-of select="name"/></div>
			   <br></br>
			   Birth: <xsl:value-of select="birth"/>
			   <br></br>
			   Height: <xsl:value-of select="height"/> 
			   <br></br>
				Email: <a><xsl:attribute name="href"><xsl:value-of select="email" /></xsl:attribute><xsl:value-of select="email" /></a>
				<br></br>
				Phones:
				<div class='phones'>
					<xsl:for-each select="phones">
						 <xsl:value-of select="phone"/>
					</xsl:for-each>
				</div>
		</xsl:for-each>
	  </body>
	  </html>
	</xsl:template>
</xsl:stylesheet>